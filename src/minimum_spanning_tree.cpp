// Copyright (c) 2018 Jacopo Notarstefano

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

class DisjointSet {
 public:
  explicit DisjointSet(int n): ids_(n), sizes_(n, 1) {
    std::iota(ids_.begin(), ids_.end(), 0);
  }

  bool are_disjoint(int p, int q) {
    return root(p) != root(q);
  }

  void join(int p, int q) {
    int i = root(p), j = root(q);

    if (i == j) {
      return;
    } else if (sizes_[i] < sizes_[j]) {
      ids_[i] = j;
      sizes_[j] += sizes_[i];
    } else {
      ids_[j] = i;
      sizes_[i] += sizes_[j];
    }
  }

 private:
  std::vector<int> ids_;
  std::vector<int> sizes_;

  int root(int p) {
    while (p != ids_[p]) {
      ids_[p] = ids_[ids_[p]];
      p = ids_[p];
    }

    return p;
  }
};

class Edge {
 public:
  int i, j;
  int64_t weight;

  explicit Edge(int i, int j, int64_t weight): i(i), j(j), weight(weight) {}

  bool operator<(const Edge& other) const {
    return weight < other.weight;
  }
};

int64_t minimum_spanning_tree(int n, std::vector<Edge>& edges) {
  int64_t result = 0;

  std::sort(edges.begin(), edges.end());

  auto disjoint_set = DisjointSet(n);
  for (const auto& edge : edges) {
    if (disjoint_set.are_disjoint(edge.i, edge.j)) {
      disjoint_set.join(edge.i, edge.j);
      result += edge.weight;
    }
  }

  return result;
}

int main() {
  std::vector<Edge> edges;

  int n, m; std::cin >> n >> m;

  for (int k = 0; k < m; k++) {
    int i, j; std::cin >> i >> j;
    int64_t weight; std::cin >> weight;
    edges.push_back(Edge(i - 1, j - 1, weight));
  }

  std::cout << minimum_spanning_tree(n, edges) << std::endl;
}
