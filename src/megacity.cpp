// Copyright (c) 2018 Jacopo Notarstefano

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

#define MEGACITY_POP 1000000

class City {
 public:
  int x, y, pop;

  explicit City(int x, int y, int pop): x(x), y(y), pop(pop) {}

  double distance() const {
    return std::sqrt(squaredDistance());
  }

  double squaredDistance() const {
    return x * x + y * y;
  }

  bool operator<(const City& other) const {
    return squaredDistance() < other.squaredDistance();
  }
};

long double megacity(int n, int current_pop, std::vector<City>& cities) {
  std::sort(cities.begin(), cities.end());

  for (int i = 0; i < n; i++) {
    current_pop += cities[i].pop;
    if (current_pop >= MEGACITY_POP) {
      return cities[i].distance();
    }
  }

  return -1;
}

int main() {
  std::vector<City> cities;

  int n; std::cin >> n;
  int current_pop; std::cin >> current_pop;

  for (int i = 0; i < n; i++) {
    int x, y, pop; std::cin >> x >> y >> pop;
    cities.push_back(City(x, y, pop));
  }

  std::cout << std::setprecision(8) << megacity(n, current_pop, cities) << std::endl;
}
