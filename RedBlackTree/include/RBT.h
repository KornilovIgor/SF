#pragma once

enum Color { Black, Red };

class RBTree
{
    struct Node
    {
        int key;
        Color color;
        Node* left;
        Node* right;
        Node* parent;
        Node(int k) :
            key(k),
            color(Red),
            parent(nullptr),
            left(nullptr),
            right(nullptr)
        {};
    };

    Node* root;

    void insert(Node* root, Node* node);
    void InsertFixUp(Node*& root, Node* node);
    Node* search(Node*node, int key) const;
    void remove(Node*& root, Node* node);
    void removeFixUp(Node*& root, Node* node, Node* parent);

public:
    void insert(int key);
    Node* search(int key);
    void remove(int key);
};