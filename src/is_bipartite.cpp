// Copyright (c) 2018 Jacopo Notarstefano

#include <stack>
#include <unordered_map>

enum Color {
  BLACK,
  WHITE,
};

bool isBipartite(int G[][MAX], int v) {
  std::unordered_map<int, Color> color;
  for (int node = 0; node < v; node++) {
    if (color.find(node) != color.end()) {
      continue;
    }
    color[node] = BLACK;

    std::stack<int> stack;
    stack.push(node);
    while (!stack.empty()) {
      auto current = stack.top();
      stack.pop();

      for (int neighbor = 0; neighbor < v; neighbor++) {
        if (G[current][neighbor]) {
          if (color.find(neighbor) == color.end()) {
            if (color[current] == BLACK) {
              color[neighbor] = WHITE;
            } else if (color[current] == WHITE) {
              color[neighbor] = BLACK;
            }

            stack.push(neighbor);
          } else if (color[current] == color[neighbor]) {
            return false;
          }
        }
      }
    }
  }

  return true;
}
