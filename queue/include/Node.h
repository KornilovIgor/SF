#pragma once

class Node
{
public:
    int m_data;
    Node *m_next{nullptr};

    explicit Node(int data):
        m_data(data),
        m_next(nullptr)
    {}
};