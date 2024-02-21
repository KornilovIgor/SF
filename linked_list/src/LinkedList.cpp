#include "LinkedList.h"

#include <iostream>

Node::Node(int data):_data(data), _next(nullptr){}

List::List():_head(nullptr){}

void List::pushBack(int data)
{
    Node* node = new Node (data);

    if (_head == nullptr)
    {
        _head = node;
        return;
    }
    Node* last = _head;
    while (last->_next != nullptr)
    {
        last = last->_next;
    }
    last->_next = node;
}

void List::pushFront(int data)
{
    Node* node = new Node (data);
    node->_next = _head;
    _head = node;
}

void List::insert(int pos, int data)
{
    Node *node = new Node (data);

    if (_head == nullptr)
    {
        _head = node;
        return;
    }

    if (pos == 0)
    {
        node->_next = _head;
        _head = node;
        return;
    }

    int currPos = 0;

    Node* current = _head;
    while (currPos < pos -1 && current->_next != nullptr )
    {
        current = current->_next;
        ++currPos;
    }
    Node *next = current->_next;
    current->_next = node;
    node->_next = next;
}

void List::show() const
{
    if (_head == nullptr)
    {
        std::cout << "List is empty\n";
        return;
    }

    Node *current = _head;

    std::cout << "List:";
    while (current != nullptr)
    {
        std::cout << ' ' << current->_data;
        current = current->_next;
    }
    std::cout << std::endl;
}

void List::deleteNode(int data)
{
    //Empty list
    if (_head == nullptr)
    {
        return;
    }

    Node *current {_head};

    //Delete first node
    if (_head != nullptr && _head->_data == data)
    {
        _head = current->_next;
        delete current;
        return;
    }

    //Find node
    Node *prev {nullptr};
    while (current != nullptr && current->_data != data)
    {
        prev = current;
        current = current->_next;
    }

    if (current == nullptr) //if not found
    {
        return;
    }

    prev->_next = current->_next;
    delete current;
}

void List::deleteNodePos(int pos)
{
    if (_head == nullptr || pos < 0)
    {
        return;
    }

    Node* current {_head};
    if (pos == 0)
    {
        _head = current->_next;
        delete current;
        return;
    }

    Node* prev {nullptr};
    int currentPos{0};
    while (currentPos != pos && current != nullptr)
    {
        prev = current;
        current = current->_next;
        currentPos++;
    }

    if (current == nullptr) //if not found
    {
        return;
    }

    prev->_next = current->_next;
    delete current;
}

void List::clear()
{
    Node *current {_head};

    while (current != nullptr)
    {
        _head = current->_next;
        delete current;
        current = _head;
    }
}