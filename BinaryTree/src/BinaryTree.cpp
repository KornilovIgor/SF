#include "BinaryTree.h"

BinaryTree::Node::Node(int d, Node* p):
    data(d), parent(p) {
   leftChild = nullptr;
   rightChild = nullptr;
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
        delete root; //???
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

    //Delete Node with two child
    Node *current = delNode->leftChild;

    if (isLeaf(current))
    {
        current->rightChild = delNode->rightChild;
        delNode->rightChild->parent = current;
        delNode->leftChild = nullptr;
        delNode->rightChild = nullptr;
        delete delNode;
        return;
    }
    else
    {
        while(current->rightChild != nullptr)
        {
            current = current->rightChild;
        }

        current->parent->rightChild = nullptr; //18 -> nullptr
        current->rightChild = delNode->rightChild; // 19 -> 43
        current->leftChild = delNode->leftChild; // 13 <- 19
        delNode->rightChild->parent = current; // 43 ^ 19

        delNode->leftChild = nullptr;
        delNode->rightChild = nullptr;

        if (delNode->parent->leftChild == delNode)
        {
            delNode->parent->leftChild = current;
        }
        else if (delNode->parent->rightChild == delNode)
        {
            delNode->parent->rightChild = current;
        }

        delete delNode;
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
        else if (Leaf->parent->rightChild == Leaf)
        {
            Leaf->parent->rightChild = nullptr;
        }

        delete Leaf;
        return;
    }
}

void BinaryTree::delNodeWithOneChild(Node* delNode)
{
    //если есть левый потомок
    if (delNode->leftChild)
    {
        delNode->leftChild->parent = delNode->parent;

        if (delNode == delNode->parent->leftChild)
        {
            delNode->parent->leftChild = delNode->leftChild;
        }
        else
        {
            delNode->parent->rightChild = delNode->leftChild;
        }
    }
    else if (delNode->rightChild)
    {
        delNode->rightChild->parent = delNode->parent;

        if (delNode == delNode->parent->leftChild)
        {
            delNode->parent->leftChild = delNode->rightChild;
        }
        else
        {
            delNode->parent->rightChild = delNode->rightChild;
        }
    }

    delNode->leftChild = nullptr;
    delNode->rightChild = nullptr;
    delNode->parent = nullptr;
    delete delNode;
}


void BinaryTree::symmetricWalk(int output_array[]) {
    if (root == nullptr)
    {
        return;
    }

    //Morris Inorder Traversal
    Node* current = root;
    int i = 0;
    while (current != nullptr)
    {
        if (current->leftChild == nullptr)
        {
            output_array[i++] = current->data;
            current = current->rightChild;
        }
        else
        {
            Node* prev = current->leftChild;
            while (prev->rightChild != nullptr && prev->rightChild != current)
            {
                prev = prev->rightChild;
            }

            if (prev->rightChild == nullptr)
            {
                prev->rightChild = current;
                current = current->leftChild;
            }
            else
            {
                prev->rightChild = nullptr;
                output_array[i++] = current->data;
                current = current->rightChild;
            }
        }
    }
}


/*Реализация от автора задания 13.8.2:

BinaryTree::Node* BinaryTree::findNodeByData(int finddata) {
    Node* current =  root;
    while(current != nullptr) {
        if(current->data == finddata){
            return current;
        }

        if(current->data > finddata) {
            current = current->leftChild;
        } else {
            current = current->rightChild;
        }
    }
    return nullptr;
}

void BinaryTree::delInt(int deldata) {
    Node* foundForDel = findNodeByData(deldata);
    if (foundForDel == nullptr)
        return; // такого целого числа нет в дереве
    // такое целое есть
    if (isLeaf(foundForDel)) { // если это лист, просто удалим его
       delLeaf(foundForDel);
    } else {
        // если не лист, то удаление сложнее
        if(foundForDel->leftChild == nullptr || foundForDel->rightChild == nullptr) {
            // случай, когда у узла только один дочерний
            delNodeWithOneChild(foundForDel);
        } else {
            // ищем правый элемент левого поддерева
            Node* mostright = foundForDel->leftChild;
            while(mostright->rightChild != nullptr)
                mostright = mostright->rightChild;

            // записали данные из правого вместо данных в удаляемом узле
            foundForDel->data = mostright->data;

            // удалили правый элемент (он может содержать только левый узел)
            if(mostright->leftChild != nullptr)
                delNodeWithOneChild(mostright);
            else
                delLeaf(mostright);
        }
    }
}

// установка для родителя узла child нового дочернего
// узла newChild вместо child (для дальнейшего удаления узла)
void BinaryTree::setNewChild(Node* child, Node* newChild = nullptr) {
    Node* parent = child->parent;
    if(parent != nullptr) {
        if(parent->leftChild == child) {
            parent->leftChild = newChild;
        } else {
            parent->rightChild = newChild;
        }
    }
}

// удалить узел с одним дочерним узлом из дерева
void BinaryTree::delNodeWithOneChild(Node* delNode) {
    if(delNode->leftChild != nullptr) {
        // если имеет левый узел
        if(isRoot(delNode)) {
            root = delNode->leftChild;
        } else {
            setNewChild(delNode, delNode->leftChild);
        }
        delNode->leftChild->parent = delNode->parent;
        delNode->leftChild = nullptr;
    } else {
        // если правый узел
        if(isRoot(delNode)) {
            root = delNode->rightChild;
        } else {
            setNewChild(delNode, delNode->rightChild);
        }
        delNode->rightChild->parent = delNode->parent;
        delNode->rightChild = nullptr;
    }
    // удаляем узел
    delete delNode;
}
// удалить лист из дерева
void BinaryTree::delLeaf(Node* leaf){
    if(isRoot(leaf)) { // случай, когда в дереве всего один корневой узел
        // забываем корень
        root = nullptr;
    }
    else {
        // обнуляем указатель на удаляемый узел у родителя
        setNewChild(leaf);
    }
    // удаляем листовой узел
    delete leaf;
}
*/

/* Реализация от автора задания 13.8.3:
// симметричный обход
void BinaryTree::symmetricWalk(int output_array[]) {
       if (root != nullptr)
       {
         int counter = 0;
         symmetricWackInner(output_array,counter, root);
       }
}

void BinaryTree::symmetricWackInner(int output_array[], int& counter, Node* current){
    // обработали левый
    if(current->leftChild != nullptr) {
        symmetricWackInner(output_array, counter,current->leftChild);
    }
    output_array[counter++] = current->data; // вывели себя
    //обработали правый
    if(current->rightChild != nullptr) {
        symmetricWackInner(current->rightChild);
    }
}
*/