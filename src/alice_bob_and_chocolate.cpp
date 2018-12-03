// Copyright (c) 2018 Jacopo Notarstefano

#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

std::pair<int, int> alice_bob_and_chocolate(const std::vector<int>& times) {
  int prefix_sum = 0,
      suffix_sum = std::accumulate(times.begin(), times.end(), 0);

  int i = 0;
  while (i < times.size() && prefix_sum < suffix_sum) {
    prefix_sum += times[i];
    suffix_sum -= times[i];
    i++;
  }

  if (i > 0 && suffix_sum < prefix_sum - times[i - 1]) {
    i--;
  }

  return std::pair<int, int>(i, times.size() - i);
}

int main() {
  std::vector<int> times;

  int n; std::cin >> n;
  for (int i = 0; i < n; i++) {
    int time; std::cin >> time;
    times.push_back(time);
  }

  auto result = alice_bob_and_chocolate(times);
  std::cout << result.first << ' ' << result.second << std::endl;
}
