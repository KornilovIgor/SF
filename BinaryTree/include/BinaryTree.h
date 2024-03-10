#pragma once

class BinaryTree {
    public:
        struct Node { // структура узла
            Node(int d, Node* p = nullptr);
            ~Node();
            Node* parent; // родительский узел

            Node* leftChild; // левый узел
            Node* rightChild; // правый узел

            int data; // данные - целое число
        };

        BinaryTree();
        ~BinaryTree();

        void addInt(int newdata);

        Node* findNodeByData(int finddata);
        void delInt(int deldata);

        void print();

        void symmetricWalk(int output_array[]);

    private:
void setNewChild(Node* child, Node* newChild = nullptr);
    void delNodeWithOneChild(Node* delNode);
    void delLeaf(Node* leaf);
    // проверка является ли узел листом
    bool isLeaf(Node* check);
    // проверка, являтся ли узел корневым
    bool isRoot(Node* check);
    Node* root; // корневой узел
    void inorder(Node* root);
};
