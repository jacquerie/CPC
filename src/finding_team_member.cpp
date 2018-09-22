// Copyright (c) 2018 Jacopo Notarstefano
//
// We sort the teams by decreasing strength, then we greedily select a team if
// both its members were not already selected. Note that the cost is given in
// terms of the number of teams, and not the number of people.
//
// Time: O(n log n), Space: O(n)

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Team {
 public:
    int i, j, strength;

    explicit Team(int i, int j, int strength): i(i), j(j), strength(strength) {}

    bool operator>(const Team& other) const {
        return strength > other.strength;
    }
};

std::unordered_map<int, int> finding_team_member(std::vector<Team>& teams) {
    std::unordered_map<int, int> assignment;

    std::sort(teams.begin(), teams.end(), std::greater<void>());

    for (const auto& team : teams) {
        bool i_not_found = assignment.find(team.i) == assignment.end(),
             j_not_found = assignment.find(team.j) == assignment.end();
        if (i_not_found && j_not_found) {
            assignment[team.i] = team.j;
            assignment[team.j] = team.i;
        }
    }

    return assignment;
}

int main() {
    std::vector<Team> teams;

    int n; std::cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j < i; j++) {
            int strength; std::cin >> strength;
            teams.push_back(Team(i, j, strength));
        }
    }

    std::unordered_map<int, int> assignment = finding_team_member(teams);
    for (int i = 1; i <= 2 * n; i++) {
        std::cout << assignment[i] << ' ';
    }
    std::cout << std::endl;
}
