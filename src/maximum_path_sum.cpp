// Copyright (c) 2018 Jacopo Notarstefano
//
// Each child returns to the parent two numbers: the first is the maximum sum
// of a path ending in the child, the second is the maximum sum of a path in
// the subtree rooted at the child. Then the parent can recursively compute
// these two numbers from its children:
//
//   1. The maximum sum of a path ending in the parent is the maximum of the
//      maximum sums of the paths ending in one of the children plus the value
//      of the parent, unless they are both negative, in which case we discard
//      both.
//
//   2. The maximum sum of a path in the subtree rooted at the parent is the
//      maximum of the maximum sums of the paths in the subtrees rooted at one
//      of the children and the sum of the path made by concatenating the
//      maximum paths ending in the children plus the value of the parent.
//
// Time: O(n), Space: O(1)

#include <algorithm>
#include <climits>
#include <utility>

std::pair<int, int> maxPathSumHelper(Node* root) {
  if (!root) {
    return std::pair<int, int>(0, INT_MIN);
  } else {
    auto leftResult = maxPathSumHelper(root->left);
    auto rightResult = maxPathSumHelper(root->right);

    return std::pair<int, int>(
      std::max({
        leftResult.first + root->data,
        0,
        rightResult.first + root->data
      }),
      std::max({
        leftResult.second,
        leftResult.first + root->data + rightResult.first,
        rightResult.second
      }));
  }
}

int maxPathSum(Node* root) {
  return maxPathSumHelper(root).second;
}
