#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

const int $ = -1;

struct TreeLinkNode {
    int           val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeLinkNode *NewTreeLink(std::initializer_list<int> li) {
    TreeLinkNode  prev(0);
    TreeLinkNode *node = &prev;

    std::queue<TreeLinkNode *> nodes;

    int is_left = false;
    for (int i : li) {
        if (is_left) {
            if (i != $) {
                node->left = new TreeLinkNode(i);
                nodes.push(node->left);
            }
            is_left = false;
        } else {
            if (i != $) {
                node->right = new TreeLinkNode(i);
                nodes.push(node->right);
            }
            node = nodes.front();
            nodes.pop();
            is_left = true;
        }
    }

    return prev.right;
}

void DestroyTreeLink(TreeLinkNode *node) {
    if (node != nullptr) {
        DestroyTreeLink(node->left);
        DestroyTreeLink(node->right);
        delete node;
    }
}

void TreeLinkShow(TreeLinkNode *node) {
    std::queue<TreeLinkNode *> nodes;
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

bool TreeLinkEqual(TreeLinkNode *node1, TreeLinkNode *node2) {
    if (node1 == nullptr) {
        return node2 == nullptr;
    }
    if (node2 == nullptr) {
        return false;
    }
    return node1->val == node2->val &&
           TreeLinkEqual(node1->left, node2->left) &&
           TreeLinkEqual(node1->right, node2->right) &&
           TreeLinkEqual(node1->next, node2->next);
}