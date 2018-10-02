// Copyright (c) 2018 Jacopo Notarstefano

#include <iostream>
#include <string>
#include <utility>
#include <vector>

std::vector<int> precompute_prefix_sums(std::string s) {
    std::vector<int> result(s.length(), 0);

    for (int i = 0; i < s.length(); i++) {
        if (i == 0) {
            result[i] = (s[i] == s[i + 1]) ? 1 : 0;
        } else {
            result[i] = result[i - 1] + ((s[i - 1] == s[i]) ? 1 : 0);
        }
    }

    return result;
}

int ilya_and_queries(const std::vector<int>& prefix_sums, const std::pair<int, int>& query) {
    return prefix_sums[query.second - 1] - prefix_sums[query.first - 1];
}

int main() {
    std::string s; std::cin >> s;

    std::vector<int> prefix_sums = precompute_prefix_sums(s);

    int m; std::cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y; std::cin >> x >> y;
        std::pair<int, int> query(x, y);

        std::cout << ilya_and_queries(prefix_sums, query) << std::endl;
    }
}
