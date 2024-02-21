#define MAX 1000

class Stack
{
private:
    int m_top;

public:
    char m_items[MAX] {};
    Stack() : m_top(-1) {}
    bool push(char x);
    char pop();
    char peek();
    bool isFull();
    bool isEmpty();
};