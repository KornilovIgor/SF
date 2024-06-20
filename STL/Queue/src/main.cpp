#include <iostream>
#include <set>

using namespace std;

void Intersection(const set<int>& s1, const set<int>& s2) {

    set<int>::iterator it;
    for (auto& el : s1)
    {
        it = s2.find(*el)
        if (it != s2.end())
        {
            cout << el << " ";
        }
    }
}

int main()
{
    std::set<int> mySet;
    mySet.insert(5);
    mySet.insert(2);
    mySet.insert(8);


    std::set<int> mySet2;
    mySet2.insert(2);
    mySet2.insert(8);
    mySet2.insert(1);
    mySet2.insert(4);

    Intersection(mySet, mySet2);
}