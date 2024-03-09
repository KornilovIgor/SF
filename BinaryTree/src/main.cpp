#include "BinaryTree.h"

#include <iostream>

int main() {

    BinaryTree binaryTree;


    binaryTree.addInt((int)(2));
    binaryTree.addInt((int)(1));
    binaryTree.addInt((int)(4));
    binaryTree.addInt((int)(7));
    binaryTree.addInt((int)(5));
    binaryTree.addInt((int)(3));
    std::cout << "\nTree:\n"; binaryTree.print();


    std::cout << "\n" << (int)(1) << " : " << binaryTree.findNodeByData((int)(1)) << std::endl;

    binaryTree.delInt((int)(1));

    std::cout << "\nTree:\n"; binaryTree.print();

    return 0;
}
