#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

const int $ = -1;

struct TreeNode {
    int       val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *NewTree(std::initializer_list<int> li) {
    TreeNode  prev(0);
    TreeNode *node = &prev;

    std::queue<TreeNode *> nodes;

    int is_left = false;
    for (int i : li) {
        if (is_left) {
            if (i != $) {
                node->left = new TreeNode(i);
                nodes.push(node->left);
            }
            is_left = false;
        } else {
            if (i != $) {
                node->right = new TreeNode(i);
                nodes.push(node->right);
            }
            node = nodes.front();
            nodes.pop();
            is_left = true;
        }
    }

    return prev.right;
}

void DestroyTree(TreeNode *node) {
    if (node != nullptr) {
        DestroyTree(node->left);
        DestroyTree(node->right);
        delete node;
    }
}

void TreeShow(TreeNode *node) {
    std::queue<TreeNode *> nodes;
    nodes.push(node);
    std::cout << node->val << ", ";
    while (!nodes.empty()) {
        node = nodes.front();
        nodes.pop();
        if (node->left != nullptr) {
            nodes.push(node->left);
            std::cout << node->left->val << ", ";
        } else {
            std::cout << "$, ";
        }
        if (node->right != nullptr) {
            nodes.push(node->right);
            std::cout << node->right->val << ", ";
        } else {
            std::cout << "$, ";
        }
    }
    std::cout << std::endl;
}

bool TreeEqual(TreeNode *node1, TreeNode *node2) {
    if (node1 == nullptr) {
        return node2 == nullptr;
    }
    if (node2 == nullptr) {
        return false;
    }
    return node1->val == node2->val &&
           TreeEqual(node1->left, node2->left) &&
           TreeEqual(node1->right, node2->right);
}