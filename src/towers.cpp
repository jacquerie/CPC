// Copyright (c) 2018 Jacopo Notarstefano
//
// We keep track in an unordered map of the number of bars of a given length
// that we see. Whenever we see a length for the first time we increment the
// number of towers by 1, and for each bar we check whether its tower has now
// become the tallest. Finally, we return the height of the tallest tower and
// the number of towers as a pair.
//
// Time: O(n), Space: O(n)

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

std::pair<int, int> towers(const std::vector<int>& bars) {
    int max_tower = 0, number_of_towers = 0;

    std::unordered_map<int, int> counts;
    for (const auto& bar : bars) {
        if (counts.find(bar) == counts.end()) {
            number_of_towers++;
        }

        counts[bar]++;
        max_tower = std::max(max_tower, counts[bar]);
    }

    return std::pair<int, int>(max_tower, number_of_towers);
}

int main() {
    std::vector<int> bars;

    int n; std::cin >> n;
    for (int j = 0; j < n; j++) {
        int bar; std::cin >> bar;
        bars.push_back(bar);
    }

    std::pair<int, int> result = towers(bars);
    std::cout << result.first << ' ' << result.second << std::endl;
}
