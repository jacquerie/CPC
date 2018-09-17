// Copyright (c) 2018 Jacopo Notarstefano

#include <algorithm>
#include <iostream>
#include <vector>

int trapping_rain_water(const std::vector<int>& heights) {
    std::vector<int> tallest_left(heights.size(), 0);
    for (int i = 0; i < heights.size(); i++) {
        tallest_left[i] = std::max(
            heights[i], (i != 0) ? tallest_left[i - 1] : 0);
    }

    std::vector<int> tallest_right(heights.size(), 0);
    for (int i = heights.size() - 1; i >= 0; i--) {
        tallest_right[i] = std::max(
            heights[i], (i != heights.size() - 1) ? tallest_right[i + 1] : 0);
    }

    int result = 0;

    for (int i = 0; i < heights.size(); i++) {
        result += std::min(tallest_left[i], tallest_right[i]) - heights[i];
    }

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

        std::cout << trapping_rain_water(nums) << std::endl;

        nums.clear();
    }
}
