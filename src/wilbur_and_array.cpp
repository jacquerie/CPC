// Copyright (c) 2018 Jacopo Notarstefano
//
// We start by using |b_1| moves that add or subtract one to all elements,
// depending on the sign of b_1. This makes all elements, in particular the
// second one, equal to b_1. We will then need |b_2 - b_1| moves that operate
// on all elements except the first one to make the second equal to b_2. The
// same argument applies inductively to the i-th element, which will then
// require |b_i - b_{i - 1}| moves to become equal to b_i. Therefore, the total
// amount of moves is |b_1| + \sum_{i = 2}^{n}{|b_i - b_{i - 1}|}.
//
// Time: O(n), Space: O(1)

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
