// Copyright (c) 2018 Jacopo Notarstefano

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int edit_distance(int p, int q, std::string str1, std::string str2) {
  std::vector<std::vector<int>> result(p + 1, std::vector<int>(q + 1));

  for (int i = 0; i < p + 1; i++) {
    for (int j = 0; j < q + 1; j++) {
      if (i == 0 && j == 0) {
        result[i][j] = 0;
      } else if (i == 0) {
        result[i][j] = j;
      } else if (j == 0) {
        result[i][j] = i;
      } else {
        result[i][j] = std::min({
            result[i - 1][j] + 1,
            result[i][j - 1] + 1,
            result[i - 1][j - 1] + (str1[i - 1] == str2[j - 1] ? 0 : 1),
        });
      }
    }
  }

  return result[p][q];
}

int main() {
  int t; std::cin >> t;
  for (int i = 0; i < t; i++) {
    int p, q; std::cin >> p >> q;
    std::string str1; std::cin >> str1;
    std::string str2; std::cin >> str2;

    std::cout << edit_distance(p, q, str1, str2) << std::endl;
  }
}
