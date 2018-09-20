// Copyright (c) 2018 Jacopo Notarstefano
//
// We do three passes over the array:
//
//     1. In the first pass, we write in the i-th element of tallest_left
//        the height of the tallest tower to the left of the i-th tower.
//
//     2. In the second pass, we write in the i-th element of tallest_right
//        the height of the tallest tower to the right of the i-th tower.
//
//     3. In the third and final pass, we compute the result by noting that
//        the contribution of the i-th element is the difference between the
//        height of the i-th element and the minimum between tallest_left[i]
//        and tallest_right[i]. This is because the latter will tell us the
//        height of the water above the i-th element, while the former will
//        tell us how much of it is not water.
//
// Time: O(n), Space: O(n)

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
