#include "List.h"
#include <iostream>
using namespace std;

void List::push_back(int data)
{
    // создаем новый узел
    Node* node = new Node(data);
    // если список пуст, возвращаем узел
    if (m_head == nullptr)
    {
        m_head = node;
        return;
    }
    // в цикле ищем последний элемент списка
    Node* last = m_head;
    while (last->m_next != nullptr)
    {
        last = last->m_next;
    }
    // Обновляем указатель next последнего узла на указатель на новый узел
    last->m_next = node;
    return;
}

void List::show()
{
    Node* current = m_head;

    while (current != nullptr)
    {
        cout << current->m_data;
        current = current->m_next;
    }
}

void List::deleteNode(int position)
{
    if (m_head == nullptr)
       return;

   Node* temp = m_head;

    if (position == 0)
    {
        m_head = temp->m_next;
        delete temp;
        return;
    }

    for (int i=0; temp != nullptr && i < position-1; i++)
         temp = temp->m_next;

    if (temp == nullptr || temp->m_next == nullptr)
         return;

    Node* next = temp->m_next->m_next;
    delete temp->m_next;

    temp->m_next = next;
}

bool List::find(int data)
{
    Node* current = m_head;
    while (current != nullptr)
    {
        if (current->m_data == data)
        {
            return true;
        }
        current = current->m_next;
    }

    return false;
}