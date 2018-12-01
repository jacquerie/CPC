// Copyright (c) 2018 Jacopo Notarstefano

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

void delete_x_shape(int m, int n, std::vector<std::vector<char>>& matrix, int i, int j) {
  std::queue<std::pair<int, int>> queue;
  queue.push(std::pair<int, int>(i, j));

  while (!queue.empty()) {
    auto coordinates = queue.front();
    matrix[coordinates.first][coordinates.second] = 'O';
    queue.pop();

    if (0 < coordinates.first && matrix[coordinates.first - 1][coordinates.second] == 'X') {
      queue.push(std::pair<int, int>(coordinates.first - 1, coordinates.second));
    }
    if (0 < coordinates.second && matrix[coordinates.first][coordinates.second - 1] == 'X') {
      queue.push(std::pair<int, int>(coordinates.first, coordinates.second - 1));
    }
    if (coordinates.first < m - 1 && matrix[coordinates.first + 1][coordinates.second] == 'X') {
      queue.push(std::pair<int, int>(coordinates.first + 1, coordinates.second));
    }
    if (coordinates.second < n - 1 && matrix[coordinates.first][coordinates.second + 1] == 'X') {
      queue.push(std::pair<int, int>(coordinates.first, coordinates.second + 1));
    }
  }
}

int x_total_shapes(int m, int n, std::vector<std::vector<char>>& matrix) {
  int result = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 'X') {
        delete_x_shape(m, n, matrix, i, j);
        result++;
      }
    }
  }

  return result;
}

int main() {
  int t; std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::vector<std::vector<char>> matrix;

    int m; std::cin >> m;
    int n; std::cin >> n;

    for (int j = 0; j < m; j++) {
      std::vector<char> row;

      for (int k = 0; k < n; k++) {
        char c; std::cin >> c;
        row.push_back(c);
      }
      matrix.push_back(row);

      row.clear();
    }

    std::cout << x_total_shapes(m, n, matrix) << std::endl;

    matrix.clear();
  }
}
