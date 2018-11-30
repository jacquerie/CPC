// Copyright (c) 2018 Jacopo Notarstefano

#include <algorithm>
#include <iostream>
#include <vector>

int longest_increasing_subsequence(int n, const std::vector<int>& nums) {
  std::vector<int> result(n, 1);

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (nums[i] < nums[j]) {
        result[j] = std::max(result[j], 1 + result[i]);
      }
    }
  }

  return *std::max_element(result.begin(), result.end());
}

int main() {
  int t; std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::vector<int> nums;

    int n; std::cin >> n;
    for (int j = 0; j < n; j++) {
      int num; std::cin >> num;
      nums.push_back(num);
    }

    std::cout << longest_increasing_subsequence(n, nums) << std::endl;

    nums.clear();
  }
}
