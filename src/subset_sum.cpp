// Copyright (c) 2018 Jacopo Notarstefano

#include <iostream>
#include <numeric>
#include <vector>

bool subset_sum(int n, const std::vector<int>& nums) {
  int sum = std::accumulate(nums.begin(), nums.end(), 0);
  if (sum % 2 == 1) {
    return false;
  }

  std::vector<std::vector<bool>> result(n + 1, std::vector<bool>(sum / 2 + 1, false));

  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < sum / 2 + 1; j++) {
      if (j == 0) {
        result[i][j] = true;
      } else if (i == 0) {
        result[i][j] = false;
      } else if (nums[i - 1] > j) {
        result[i][j] = result[i - 1][j];
      } else {
        result[i][j] = result[i - 1][j] || result[i - 1][j - nums[i - 1]];
      }
    }
  }

  return result[n][sum / 2];
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

    std::cout << (subset_sum(n, nums) ? "YES" : "NO") << std::endl;

    nums.clear();
  }
}
