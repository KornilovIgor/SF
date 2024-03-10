#include "BinaryTree.h"

#include <iostream>

void BinaryTree::print()
{
    inorder(root);
}

// A utility function to do inorder traversal of BST
void BinaryTree::inorder(Node* root)
{
    if (root != NULL) {
        inorder(root->leftChild);
        std::cout << root->data << " ";
        inorder(root->rightChild);
    }
}
