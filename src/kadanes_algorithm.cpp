// Copyright (c) 2018 Jacopo Notarstefano

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int kadanes_algorithm(const std::vector<int>& nums) {
    int best_max = INT_MIN, current_max = 0;

    for (const auto& num : nums) {
        current_max = std::max(num, current_max + num);
        best_max = std::max(best_max, current_max);
    }

    return best_max;
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

        std::cout << kadanes_algorithm(nums) << std::endl;

        nums.clear();
    }
}
