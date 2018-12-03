// Copyright (c) 2018 Jacopo Notarstefano
//
// The following explanation and solution are based on the one from Wikipedia:
// https://en.wikipedia.org/wiki/Maximum_subarray_problem#Kadane's_algorithm
//
// First, we decompose the problem of finding the max sum of a subarray in the
// n problems of finding the max sum of a subarray ending with the i-th
// element. Let B_i the solution of the i-th problem: then the result that we
// want is max(B_0, B_1, ..., B_{n - 1}).
//
// Then, we observe that B_i is the maximum of nums[i] and B_{i - 1} + nums[i]:
// the former corresponds to starting a new subarray with the i-th element, the
// latter to prolonging the subarray that achieved the maximum for B_{i - 1}
// with the i-th element.
//
// Finally, we note that by associativity max(B_0, B_1, ..., B_{n - 1}) equals
// max(B_{n - 1}, max(B_{n - 2}, ...)).
//
// Time: O(n), Space: O(1)

#include <algorithm>
#include <iostream>
#include <vector>

int kadanes_algorithm(int n, const std::vector<int>& nums) {
  int max_ending_here = nums[0], max_so_far = nums[0];

  for (int i = 1; i < n; i++) {
    max_ending_here = std::max(nums[i], max_ending_here + nums[i]);
    max_so_far = std::max(max_so_far, max_ending_here);
  }

  return max_so_far;
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

    std::cout << kadanes_algorithm(n, nums) << std::endl;

    nums.clear();
  }
}
