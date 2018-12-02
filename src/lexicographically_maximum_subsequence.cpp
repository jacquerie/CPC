// Copyright (c) 2018 Jacopo Notarstefano

#include <algorithm>
#include <iostream>
#include <string>

std::string lexicographically_maximum_subsequence(std::string s) {
  std::string result;

  for (int i = s.length() - 1; i >= 0; i--) {
    if (result.empty() || (s[i] >= result.back())) {
      result.push_back(s[i]);
    }
  }

  std::reverse(result.begin(), result.end());

  return result;
}

int main() {
  std::string s; std::cin >> s;

  std::cout << lexicographically_maximum_subsequence(s) << std::endl;
}
