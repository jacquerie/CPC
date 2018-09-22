// Copyright (c) 2018 Jacopo Notarstefano

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

std::vector<int> next_larger_element(int n, const std::vector<int>& nums) {
    std::vector<int> result;

    std::stack<int> stack;
    for (int i = n - 1; i >= 0; i--) {
        int next_larger = -1;

        while (!stack.empty()) {
            int top = stack.top();
            if (top > nums[i]) {
                next_larger = top;
                break;
            }
            stack.pop();
        }
        stack.push(nums[i]);

        result.push_back(next_larger);
    }

    std::reverse(result.begin(), result.end());

    return result;
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

        for (const auto& element : next_larger_element(n, nums)) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;

        nums.clear();
    }
}
