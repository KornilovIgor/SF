#pragma once

#include <cstddef>

struct Node
{
    int key;
    Node *left;
    Node *right;
    size_t height;

    Node(int &k)
    {
        key = k;
        left = right = nullptr;
        height = 0;
    }

    Node(int &&k)
    {
        key = k;
        left = right = nullptr;
        height = 0;
    }
};

class AVL
{
    size_t height(Node *node);
    int bfactor(Node *node);

    size_t height(Node *node); // for empty tree
    int bfactor(Node *node); // diff height
    void fix_height(Node* node);
    Node* rotateRight(Node* node);
    Node* rotateLeft(Node* node);
    Node* balance(Node* const node);
    Node* removemin(Node* node);
    Node* findmin(Node* node);
    Node* insert(Node* root, Node* const node);
    Node* delete_node(Node* node, const int& key);

public:
    const Node* bfs(const int& key) const;
    const Node* dfs(const Node* node, const int& key);
    void insert(int&& key);
    void delete_node(const int& key);
    Node* AVL::delete_node(Node* node, const int& key);
    Node *_root = nullptr;
};