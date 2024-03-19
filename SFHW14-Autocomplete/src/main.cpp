#include "Trie.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <filesystem>

bool import (std::string& s, Trie &t)
{
    std::filesystem::path currentPath = std::filesystem::current_path();

    std::filesystem::path filePath = currentPath / "words.txt";
    if (std::filesystem::exists(filePath))
    {
        std::ifstream file(filePath);
        while(getline(file, s))
        {
            t.insert(s);
        }
        file.close();
        return true;
    }
    else
    {
        std::filesystem::path parentPath = currentPath.parent_path();
        filePath = parentPath / "words.txt";
        if (std::filesystem::exists(filePath))
        {
            std::ifstream file(filePath);
            while(getline(file, s))
            {
                t.insert(s);
            }
            file.close();
            return true;
        }
        else
        {
            t.insert("time");
            t.insert("way");
            t.insert("year");
            t.insert("work");
            t.insert("government");
            t.insert("day");
            t.insert("man");
            t.insert("world");
            t.insert("life");
            t.insert("part");
            return false;
        }
    }
}

int main()
{
    Trie t;

    std::string s;

    if (!import(s, t))
    {
        std::cout << "The file with the list of words was not found. File \"words.txt\" it should be in the folder with the executable file of the program or at a higher level. (Added a short dictionary.)" << std::endl;
    }

    std::string part;
    while (true)
    {
        std::cout << "Enter a part of the search word [A..z]: ";
        std::cin >> part;

        std::transform(part.begin(), part.end(), part.begin(),
            [](unsigned char c) { return std::tolower(c); });

        std::vector<std::string> variants = t.search(part);

        if (variants.empty())
        {
            std::cout << "No matches.";
        }
        else
        {
            std::cout << "Matches: ";
            for (const std::string& variant : variants)
            {
                std::cout << variant << " ";
            }
        }
        std::cout << std::endl << std::endl;
    }

    return 0;
}