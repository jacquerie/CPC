// Copyright (c) 2018 Jacopo Notarstefano

#include <ios>
#include <iostream>
#include <tuple>
#include <vector>

class FenwickTree {
 public:
  explicit FenwickTree(int n): els_(n + 2, 0) {}

  void add(int i, int k) {
    while (i < els_.size()) {
      els_[i] += k;
      i += i & -i;
    }
  }

  int sum(int i) {
    int result = 0;
    while (i > 0) {
      result += els_[i];
      i -= i & -i;
    }
    return result;
  }

 private:
  std::vector<int> els_;
};

std::vector<int> update_the_array(int n, const std::vector<std::tuple<int, int, int>>& updates, const std::vector<int>& queries) {
  std::vector<int> result;

  auto tree = FenwickTree(n);
  for (const auto& update : updates) {
    int l, r, val; std::tie(l, r, val) = update;
    tree.add(l + 1, val);
    tree.add(r + 2, -val);
  }
  for (const auto& query : queries) {
    result.push_back(tree.sum(query + 1));
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t; std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::vector<std::tuple<int, int, int>> updates;
    std::vector<int> queries;

    int n; std::cin >> n;

    int u; std::cin >> u;
    for (int j = 0; j < u; j++) {
      int l, r, val; std::cin >> l >> r >> val;
      std::tuple<int, int, int> update(l, r, val);
      updates.push_back(update);
    }

    int q; std::cin >> q;
    for (int j = 0; j < q; j++) {
      int index; std::cin >> index;
      queries.push_back(index);
    }

    for (const auto& result : update_the_array(n, updates, queries)) {
      std::cout << result << std::endl;
    }

    updates.clear();
    queries.clear();
  }
}
