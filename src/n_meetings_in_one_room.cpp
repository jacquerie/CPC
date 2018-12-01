// Copyright (c) 2018 Jacopo Notarstefano

#include <algorithm>
#include <iostream>
#include <vector>

class Meeting {
 public:
  int id, start, end;

  explicit Meeting(int id, int start, int end): id(id), start(start), end(end) {}

  bool conflicts(const Meeting& other) const {
    return !(end < other.start || start > other.end);
  }

  bool operator<(const Meeting& other) const {
    return (end < other.end) || (end == other.end && start < other.start);
  }
};

std::vector<Meeting> n_meetings_in_one_room(std::vector<Meeting>& meetings) {
  std::vector<Meeting> result;

  std::sort(meetings.begin(), meetings.end());

  for (const auto& meeting : meetings) {
    if (result.empty() || !meeting.conflicts(result.back())) {
      result.push_back(meeting);
    }
  }

  return result;
}

int main() {
  int t; std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::vector<int> starts;
    std::vector<int> ends;
    std::vector<Meeting> meetings;

    int n; std::cin >> n;

    for (int j = 0; j < n; j++) {
      int start; std::cin >> start;
      starts.push_back(start);
    }

    for (int j = 0; j < n; j++) {
      int end; std::cin >> end;
      ends.push_back(end);
    }

    for (int j = 0; j < n; j++) {
      meetings.push_back(Meeting(j + 1, starts[j], ends[j]));
    }

    for (const auto& meeting : n_meetings_in_one_room(meetings)) {
      std::cout << meeting.id << ' ';
    }
    std::cout << std::endl;

    meetings.clear();
    starts.clear();
    ends.clear();
  }
}
