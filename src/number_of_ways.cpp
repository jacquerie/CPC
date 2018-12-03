// Copyright (c) 2018 Jacopo Notarstefano

#include <cstdint>
#include <numeric>
#include <iostream>
#include <vector>

int64_t number_of_ways(const std::vector<int>& nums) {
  int64_t sum = std::accumulate(nums.begin(), nums.end(), static_cast<int64_t>(0));

  int64_t result = 0;
  if (sum % 3) {
    return result;
  }

  int64_t suffix_sum = 0;
  std::vector<int64_t> good_suffix_sums(nums.size(), 0);
  for (int i = nums.size() - 1; i >= 0; i--) {
    suffix_sum += nums[i];

    if (i == nums.size() - 1) {
      good_suffix_sums[i] = (suffix_sum == sum / 3) ? 1 : 0;
    } else {
      good_suffix_sums[i] = good_suffix_sums[i + 1] + ((suffix_sum == sum / 3) ? 1 : 0);
    }
  }

  int64_t prefix_sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    prefix_sum += nums[i];

    if (i < nums.size() - 2 && prefix_sum == sum / 3) {
      result += good_suffix_sums[i + 2];
    }
  }

  return result;
}

int main() {
  std::vector<int> nums;

  int n; std::cin >> n;
  for (int i = 0; i < n; i++) {
    int num; std::cin >> num;
    nums.push_back(num);
  }

  std::cout << number_of_ways(nums) << std::endl;
}
