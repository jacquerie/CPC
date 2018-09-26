// Copyright (c) 2018 Jacopo Notarstefano

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::string largest_even_number(const std::string& p) {
    char last_digit = 0;
    std::string result;

    std::unordered_map<char, int> counts;
    for (const auto& c : p) {
        counts[c]++;
    }

    std::vector<char> evens = {'0', '2', '4', '6', '8'};
    for (const auto& even : evens) {
        if (counts.find(even) != counts.end()) {
            counts[even]--;
            last_digit = even;
            break;
        }
    }

    std::vector<char> digits = {'9', '8', '7', '6', '5', '4', '3', '2', '1', '0'};
    for (const auto& digit : digits) {
        if (counts.find(digit) != counts.end()) {
            for (int i = 0; i < counts[digit]; i++) {
                result.push_back(digit);
            }
        }
    }

    if (last_digit) {
        result.push_back(last_digit);
    }

    return result;
}

int main() {
    int t; std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::string p; std::cin >> p;

        std::cout << largest_even_number(p) << std::endl;
    }
}
