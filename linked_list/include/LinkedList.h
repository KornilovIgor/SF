#pragma once

class Node
{
public:
    int _data;
    Node*_next;
    explicit Node(int data);
};

class List
{
    Node*_head;

public:
    List();
    void pushBack(int data);
    void pushFront(int data);
    void insert(int pos, int data);
    void show() const;
    void deleteNode(int data);
    void deleteNodePos(int pos);
    void clear();
};