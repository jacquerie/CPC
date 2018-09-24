// Copyright (c) 2018 Jacopo Notarstefano
//
// This is Merge Sort with a twist: while merging two sorted runs, if we find
// that the current element of the second run is bigger than the i-th element
// of the first, then we have found mid - i inversions, since the run is sorted.
//
// Time: O(n log n), Space: O(n)

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

int64_t merge_and_count(std::vector<int>& nums, int first, int mid, int last) {
    int64_t result = 0;
    std::vector<int> tmp;

    int i = first, j = mid;
    while (i < mid && j <= last) {
        if (nums[i] <= nums[j]) {
            tmp.push_back(nums[i++]);
        } else {
            tmp.push_back(nums[j++]);
            result += mid - i;
        }
    }
    while (i < mid) {
        tmp.push_back(nums[i++]);
    }
    while (j <= last) {
        tmp.push_back(nums[j++]);
    }

    std::copy(tmp.begin(), tmp.end(), nums.begin() + first);
    return result;
}

int64_t inversion_count(std::vector<int>& nums, int first, int last) {
    int64_t result = 0;

    if (first < last) {
        int mid = first + (last - first) / 2;
        result += inversion_count(nums, first, mid);
        result += inversion_count(nums, mid + 1, last);
        result += merge_and_count(nums, first, mid + 1, last);
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

        std::cout << inversion_count(nums, 0, n - 1) << std::endl;

        nums.clear();
    }
}
