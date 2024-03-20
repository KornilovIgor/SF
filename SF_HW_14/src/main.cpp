#include "Autocomplete.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <limits>

void toLowerCase(std::string& word)
{
    for (char& c : word)
    {
        c = std::tolower(static_cast<unsigned char>(c));
    }
}

bool import (Trie &t)
    {
        std::string word;
        std::filesystem::path currentPath = std::filesystem::current_path();

        std::filesystem::path filePath = currentPath / "words.txt";
        if (std::filesystem::exists(filePath))
        {
            std::ifstream file(filePath);
            while(getline(file, word))
            {
                t.insert(word);
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
                while(getline(file, word))
                {
                    t.insert(word);
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
    Trie dictionary;

    if (!import(dictionary))
    {
        std::cout << "The file with the list of words was not found. File \"words.txt\" it should be in the folder with the executable file of the program or at a higher level. (Added a short dictionary.)" << std::endl;
    }


    while (true)
    {
        int ch = 0;
        std::string word;
        std::string prefix;
        std::vector<std::string> variants;
        std::cout << "1 - Add to the dictionary\n2 - Dictionary search\n0 - Exit\nInput >> ";
        std::cin >> ch;
        switch (ch)
        {
        case 1:
            std::cout << "Input word [A..z]\n>> ";
            std::cin >> word;
            toLowerCase(word);
            if (!dictionary.insert(word))
            {
                std::cout << "Input error: invalid word. Only English words [A..z]\n\n";
            }
            break;
        case 2:
            std::cout << "Enter a prefix of the search word [A..z]: ";
            std::cin >> prefix;
            toLowerCase(prefix);
            variants = dictionary.search(prefix);
            if (!variants.empty())
            {
                std::cout << "Matches: ";
                for (const std::string& variant : variants)
                {
                    std::cout << variant << " ";
                }
            }
            else
            {
                std::cout << "No matches. ";
            }
            std::cout << std::endl << std::endl;
            break;
        case 0:
            return 0;
        default:
            std::cout << "Error input menu";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return 0;
}