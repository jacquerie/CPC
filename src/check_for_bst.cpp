// Copyright (c) 2018 Jacopo Notarstefano
//
// We verify whether the current element is within the current bounds, then we
// recurse in the left subtree using the current element as the new upper
// bound, and in the right subtree using the current element as the new lower
// bound. The base case is the empty tree, which is trivially a BST.
//
// Time: O(n), Space: O(1)

#include <climits>

bool isBSTHelper(Node* root, int min, int max) {
    if (!root) {
        return true;
    } else {
        return min < root->data && root->data < max &&
            isBSTHelper(root->left, min, root->data) &&
            isBSTHelper(root->right, root->data, max);
    }
}

bool isBST(Node* root) {
    return isBSTHelper(root, INT_MIN, INT_MAX);
}
