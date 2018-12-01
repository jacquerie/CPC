// Copyright (c) 2018 Jacopo Notarstefano

#include <algorithm>
#include <iostream>
#include <vector>

int zero_one_knapsack(int n, int w, const std::vector<int>& values, const std::vector<int>& weights) {
  std::vector<std::vector<int>> result(n + 1, std::vector<int>(w + 1));

  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < w + 1; j++) {
      if (i == 0) {
        result[i][j] = 0;
      } else if (weights[i - 1] > j) {
        result[i][j] = result[i - 1][j];
      } else {
        result[i][j] = std::max({
            result[i - 1][j],
            result[i - 1][j - weights[i - 1]] + values[i - 1],
        });
      }
    }
  }

  return result[n][w];
}

int main() {
  int t; std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::vector<int> values;
    std::vector<int> weights;

    int n; std::cin >> n;
    int w; std::cin >> w;

    for (int j = 0; j < n; j++) {
      int value; std::cin >> value;
      values.push_back(value);
    }

    for (int j = 0; j < n; j++) {
      int weight; std::cin >> weight;
      weights.push_back(weight);
    }

    std::cout << zero_one_knapsack(n, w, values, weights) << std::endl;

    values.clear();
    weights.clear();
  }
}
