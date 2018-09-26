// Copyright (c) 2018 Jacopo Notarstefano

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
