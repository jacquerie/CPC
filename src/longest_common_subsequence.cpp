// Copyright (c) 2018 Jacopo Notarstefano

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int longest_common_subsequence(int a, int b, std::string str1, std::string str2) {
  std::vector<std::vector<int>> result(a + 1, std::vector<int>(b + 1));

  for (int i = 0; i < a + 1; i++) {
    for (int j = 0; j < b + 1; j++) {
      if (i == 0 || j == 0) {
        result[i][j] = 0;
      } else {
        result[i][j] = std::max({
            result[i - 1][j],
            result[i][j - 1],
            result[i - 1][j - 1] + (str1[i - 1] == str2[j - 1] ? 1 : 0),
        });
      }
    }
  }

  return result[a][b];
}

int main() {
  int t; std::cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b; std::cin >> a >> b;
    std::string str1; std::cin >> str1;
    std::string str2; std::cin >> str2;

    std::cout << longest_common_subsequence(a, b, str1, str2) << std::endl;
  }
}
