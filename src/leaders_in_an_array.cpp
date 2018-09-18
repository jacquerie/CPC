// Copyright (c) 2018 Jacopo Notarstefano

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

std::vector<int> leaders_in_an_array(const std::vector<int>& nums) {
    std::vector<int> result;

    int current_max = INT_MIN;
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] >= current_max) {
            current_max = nums[i];
            result.push_back(nums[i]);
        }
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

        for (const auto& leader : leaders_in_an_array(nums)) {
            std::cout << leader << ' ';
        }
        std::cout << '\n';

        nums.clear();
    }
}
