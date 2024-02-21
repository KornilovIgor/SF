#include <iostream>
#include "Stack.h"
using namespace std;


bool Stack::isEmpty()
{
    return m_top < 0;
}

bool Stack::isFull()
{
    return m_top >= (MAX - 1);
}

bool Stack::push(char x)
{
    // если стек полон выводим сообщение на консоль и возвращаемся
    if (isFull())
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    // увеличиваем значение вершины стека и кладем на вершину стека данные
    {
        ++m_top;
        m_items[m_top] = x;
        return true;
    }
}

char Stack::pop()
{
    // если стек пуст, выводим сообщение и возращаем значение 0
    if (isEmpty())
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    // забираем значение вершины стека, уменьшаем значение вершины стек на 1 и возращаем значение
    {
        char x = m_items[m_top];
        --m_top;
        return x;
    }
}

char Stack::peek()
{
    // если стек пуст возвращаемся
    if (isEmpty()) {
        cout << "Stack is Empty";
        return 0;
    }
    else
    // возвращаем значение вершины стека без удаления данных
    {
        char x = m_items[m_top];
        return x;
    }
}