// Copyright (c) 2018 Jacopo Notarstefano

#include <iostream>
#include <string>
#include <utility>
#include <vector>

std::vector<int> precompute_queries(std::string s) {
    std::vector<int> result;

    for (int i = 0; i < s.length(); i++) {
        if (i == 0) {
            result.push_back(s[i] == s[i + 1] ? 1 : 0);
        } else {
            result.push_back(result.back() + (s[i - 1] == s[i] ? 1 : 0));
        }
    }

    return result;
}

int ilya_and_queries(const std::vector<int>& prefix_sums, const std::pair<int, int>& query) {
    return prefix_sums[query.second - 1] - prefix_sums[query.first - 1];
}

int main() {
    std::string s; std::cin >> s;

    std::vector<int> prefix_sums = precompute_queries(s);

    int m; std::cin >> m;
    for (int i = 0; i < m; i++) {
        std::pair<int, int> query;
        std::cin >> query.first;
        std::cin >> query.second;

        std::cout << ilya_and_queries(prefix_sums, query) << std::endl;
    }
}
