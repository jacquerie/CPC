// Copyright (c) 2018 Jacopo Notarstefano
//
// Using Gauss' Formula we know that the sum of the first n positive integers
// is (n * (n + 1)) / 2. So we can start from this total and subtract each
// element of the array: what's left must be the missing element.
//
// Time: O(n), Space: O(1)

#include <iostream>
#include <vector>

int missing_number_in_array(int n, const std::vector<int>& nums) {
    int result = (n * (n + 1)) / 2;

    for (const auto& num : nums) {
        result -= num;
    }

    return result;
}

int main() {
    int t; std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::vector<int> nums;

        int n; std::cin >> n;
        for (int j = 0; j < n - 1; j++) {
            int num; std::cin >> num;
            nums.push_back(num);
        }

        std::cout << missing_number_in_array(n, nums) << std::endl;

        nums.clear();
    }
}
