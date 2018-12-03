// Copyright (c) 2018 Jacopo Notarstefano

#include <climits>
#include <iostream>
#include <stack>
#include <vector>

bool preorder_traversal_and_bst(const std::vector<int>& nums) {
  std::stack<int> stack;

  int current_root = INT_MIN;
  for (const auto& num : nums) {
    if (num < current_root) {
      return false;
    } else {
      while (!stack.empty()) {
        if (num < stack.top()) {
          stack.pop();
        } else {
          current_root = stack.top();
          break;
        }
      }

      stack.push(num);
    }
  }

  return true;
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

    std::cout << (preorder_traversal_and_bst(nums) ? 1 : 0) << std::endl;

    nums.clear();
  }
}
