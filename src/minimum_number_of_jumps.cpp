// Copyright (c) 2018 Jacopo Notarstefano

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int minimum_number_of_jumps(int n, const std::vector<int>& jumps) {
  std::vector<int> result(n, INT_MAX);
  result[0] = 0;

  for (int i = 0; i < n; i++) {
    if (result[i] < INT_MAX) {
      for (int j = 1; j < jumps[i] + 1; j++) {
        if (i + j < n) {
          result[i + j] = std::min(result[i + j], 1 + result[i]);
        }
      }
    }
  }

  return (result[n - 1] < INT_MAX) ? result[n - 1] : -1;
}

int main() {
  int t; std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::vector<int> jumps;

    int n; std::cin >> n;
    for (int j = 0; j < n; j++) {
      int jump; std::cin >> jump;
      jumps.push_back(jump);
    }

    std::cout << minimum_number_of_jumps(n, jumps) << std::endl;

    jumps.clear();
  }
}
