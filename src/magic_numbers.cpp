// Copyright (c) 2018 Jacopo Notarstefano

#include <iostream>
#include <string>

bool magic_number(std::string s, int i, int length) {
  if (i == length) {
    return true;
  } else if (i + 2 < length && s[i] == '1' && s[i + 1] == '4' && s[i + 2] == '4') {
    return magic_number(s, i + 3, length);
  } else if (i + 1 < length && s[i] == '1' && s[i + 1] == '4') {
    return magic_number(s, i + 2, length);
  } else if (i < length && s[i] == '1') {
    return magic_number(s, i + 1, length);
  } else {
    return false;
  }
}

int main() {
  int n; std::cin >> n;

  std::string s = std::to_string(n);
  int i = 0, length = s.length();

  std::cout << (magic_number(s, i, length) ? "YES" : "NO") << std::endl;
}
