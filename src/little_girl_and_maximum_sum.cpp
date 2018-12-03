// Copyright (c) 2018 Jacopo Notarstefano

#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

std::vector<int> precompute_frequencies(int n, const std::vector<std::pair<int, int>>& queries) {
  std::vector<int> counts(n + 1, 0);
  std::vector<int> result(n, 0);

  for (const auto& query : queries) {
    counts[query.first - 1] += 1;
    counts[query.second] -= 1;
  }

  std::partial_sum(counts.begin(), counts.end() - 1, result.begin());

  return result;
}

int64_t little_girl_and_maximum_sum(std::vector<int>& frequencies, std::vector<int>& nums) {
  std::sort(frequencies.begin(), frequencies.end());
  std::sort(nums.begin(), nums.end());

  return std::inner_product(
    frequencies.begin(), frequencies.end(),
    nums.begin(), static_cast<int64_t>(0),
    std::plus<int64_t>(), std::multiplies<int64_t>());
}

int main() {
  std::vector<int> nums;
  std::vector<std::pair<int, int>> queries;

  int n; std::cin >> n;
  int q; std::cin >> q;

  for (int i = 0; i < n; i++) {
    int num; std::cin >> num;
    nums.push_back(num);
  }

  for (int j = 0; j < q; j++) {
    int x, y; std::cin >> x >> y;
    queries.push_back(std::pair<int, int>(x, y));
  }

  auto frequencies = precompute_frequencies(n, queries);

  std::cout << little_girl_and_maximum_sum(frequencies, nums) << std::endl;
}
