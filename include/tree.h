// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>
class Tree {
    struct Node {
        char a;
        std::vector<Node*> Nodes;
    };
    std::vector<char> change;
    Node* root = nullptr;
    void make(std::vector<char> val, Node* root) {
        for (auto i : val) {
            if (i == root->a) {
                val.erase(std::remove(val.begin(), val.end(), i),
                    val.end());
                for (auto ch : val) {
                    Node* tmp = new Node;
                    tmp->a = ch;
                    root->Nodes.push_back(tmp);
                }
            }
        }
        for (auto i : root->Nodes) {
            make(val, i);
        }
    }
    void Changes(Node* root) {
        if (root->Nodes.empty()) {
            change.push_back(root->a);
            shifts.push_back(change);
            change.clear();
        }
        for (auto i : root->Nodes) {
            change.push_back(root->a);
            Changes(i);
        }
    }

 public:
    std::vector<std::vector<char>> shifts;
    explicit Tree(std::vector<char> val) {
        root = new Node;
        root->a = ' ';
        for (auto i : val) {
            Node* tmp = new Node;
            tmp->a = i;
            root->Nodes.push_back(tmp);
        }
        for (auto i : root->Nodes) {
            make(val, i);
            Changes(i);
            change.clear();
        }
    }
};
#endif  // INCLUDE_TREE_H_
