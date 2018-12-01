// Copyright (c) 2018 Jacopo Notarstefano

#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

int64_t wilbur_and_array(int n, const std::vector<int>& nums) {
  int64_t result = abs(nums[0]);

  for (int i = 1; i < n; i++) {
    result += std::abs(nums[i] - nums[i - 1]);
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

  std::cout << wilbur_and_array(n, nums) << std::endl;
}
