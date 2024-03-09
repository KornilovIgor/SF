#include "BinaryTree.h"

#include <iostream>

BinaryTree::Node::Node(int d, Node* p):
    data(d), parent(p) {
   leftChild = nullptr;
   rightChild = nullptr;
   std::cout << this->data << " : " << this << std::endl;
}

BinaryTree::Node::~Node() {
    // чистим за собой память
    if(rightChild != nullptr)
        delete rightChild;
    if(leftChild != nullptr)
        delete leftChild;
}

BinaryTree::BinaryTree() {
    root = nullptr;
}

BinaryTree::~BinaryTree() {
    if(root != nullptr)
    {
        std::cout << "destructor!" << std::endl;
        delete root;
    }
}

void BinaryTree::addInt(int newdata) {
    if(root == nullptr) {
        // если дерево пустое, то новый элемент станет корнем
        root = new Node(newdata);
    }
    else {
        Node* current = root; // начинаем с корня
        Node* newNode = nullptr;
        while(newNode == nullptr) {
            if (current->data >= newdata) {
                // если элемент меньше текущего, идем влево
                if(current->leftChild != nullptr) {
                    current = current->leftChild;
                    continue;
                }
                // если левого узла нет, то нашли место для нового элемента
                newNode = new Node(newdata, current);
                //std::cout << newNode->data << " : " << newNode << std::endl;
                current->leftChild = newNode;
            }
            else {
                // если элемент меньше текущего, идем вправо
                if (current->rightChild != nullptr) {
                    current = current->rightChild;
                    continue;
                }
                // если правого узла нет, то нашли место для нового элемента
                newNode = new Node(newdata, current);
                current->rightChild = newNode;
            }
        }
    }
}
// проверка является ли узел листом
bool BinaryTree::isLeaf(Node* check) {
    return check->leftChild == nullptr
           && check->rightChild == nullptr;
}

// проверка, являтся ли узел корневым
bool BinaryTree::isRoot(Node* check) {
    return check == root;
}
//---------
BinaryTree::Node* BinaryTree::findNodeByData(int finddata) {
    Node *current = root;

    while (current)
    {
        if (current->data == finddata)
        {
            return current;
        }

        if (current->data > finddata)
        {
            current = current->leftChild;
            continue;
        }
        else
        {
            current = current->rightChild;
        }
    }

    return nullptr;
}
// удаление элемента
void BinaryTree::delInt(int deldata)
{
    //Tree is empty
    if (root == nullptr)
    {
        return;
    }

    Node *delNode = findNodeByData(deldata);

    //Delete Leaf
    if (isLeaf(delNode))
    {
        delLeaf(delNode);
        return;
    }

    //Delete Node with one child
    if (!delNode->leftChild && delNode->rightChild
        || delNode->leftChild && !delNode->rightChild)
    {
        delNodeWithOneChild(delNode);
        return;
    }

}

void BinaryTree::delLeaf(Node* Leaf)
{
    if (isRoot(Leaf))
    {
        delete Leaf;
        root = nullptr;
        return;
    }
    else
    {
        if (Leaf->parent->leftChild == Leaf)
        {
            Leaf->parent->leftChild = nullptr;
        }
        else
        {
            Leaf->parent->rightChild = nullptr;
        }
        delete Leaf;
        return;
    }
}

void BinaryTree::delNodeWithOneChild(Node* delNode)
{
    if (delNode->leftChild)
    {

    }
}