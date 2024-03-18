#include "Trie.h"

#include <iostream>
#include <fstream>

int main()
{
    Trie t;

    std::string s;
    std::ifstream file("../words");

    while(getline(file, s))
    {
        t.insert(s);
    }
    file.close();

    std::string part;
    while (true)
    {
        std::cout << "Enter a part of the search word [A..z]: ";
        std::cin >> part;

        for (char &c: part)
        {
            if (c >= 'A' && c <= 'Z')
            {
                c += 32;
            }
        }

        std::vector<std::string> variants = t.search(part);

        std::cout << "Matches: ";
        for (const std::string& variant : variants)
        {
            std::cout << variant << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}