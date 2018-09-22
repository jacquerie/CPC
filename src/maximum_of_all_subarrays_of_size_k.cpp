// Copyright (c) 2018 Jacopo Notarstefano

#include <deque>
#include <iostream>
#include <vector>

std::vector<int> maximum_of_all_subarrays_of_size_k(int n, int k, std::vector<int> nums) {
    std::vector<int> result;

    std::deque<int> deque;
    for (int i = 0; i < n; i++) {
        while ((!deque.empty()) && deque.front() <= i - k) {
            deque.pop_front();
        }
        while ((!deque.empty()) && nums[i] >= nums[deque.back()]) {
            deque.pop_back();
        }
        deque.push_back(i);

        if (i >= k - 1) {
            result.push_back(nums[deque.front()]);
        }
    }

    return result;
}

int main() {
    int t; std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::vector<int> nums;

        int n; std::cin >> n;
        int k; std::cin >> k;
        for (int j = 0; j < n; j++) {
            int num; std::cin >> num;
            nums.push_back(num);
        }

        for (const auto& max : maximum_of_all_subarrays_of_size_k(n, k, nums)) {
            std::cout << max << ' ';
        }
        std::cout << std::endl;

        nums.clear();
    }
}
