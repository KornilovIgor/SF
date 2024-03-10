#include "BinaryTree.h"

const int SIZE = 10;
int curSize = 0;

#include <iostream>

int main() {

    BinaryTree binaryTree;


    binaryTree.addInt((int)(5)); curSize++;
    binaryTree.addInt((int)(4)); curSize++;
    binaryTree.addInt((int)(20)); curSize++;
    binaryTree.addInt((int)(-17)); curSize++;
    binaryTree.addInt((int)(13)); curSize++;
    binaryTree.addInt((int)(11)); curSize++;
    binaryTree.addInt((int)(18)); curSize++;
    binaryTree.addInt((int)(15)); curSize++;
    binaryTree.addInt((int)(19)); curSize++;
    binaryTree.addInt((int)(43)); curSize++;
    std::cout << "\nTree:\n"; binaryTree.print();

    binaryTree.delInt((int)(20)); curSize--;

    std::cout << "\nTree:\n"; binaryTree.print();

    int array[SIZE] {0};

    binaryTree.symmetricWalk(array);

    std::cout << "\nTree:\n";

    for (int i = 0; i < curSize; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
