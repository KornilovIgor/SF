#include "Stack.h"
#include <string>
#include <iostream>
using namespace std;

/*
( 40    [ 91    { 123
) 41    ] 93    } 125
*/

bool BracketsBalanced(string expr)
{
    Stack stack;
    for (char const &c: expr)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            stack.push(c);
            continue;
        }

        if (stack.isEmpty())
        {
            return false;
        }

        int top = stack.pop();
        if ((c == 41 && top != 40)
        || (c == 91 && top != 93)
        || (c == 123 && top != 125))
        {
            return false;
        }
    }

    if (stack.isEmpty())
    {
        return true;
    }

    return false;
}