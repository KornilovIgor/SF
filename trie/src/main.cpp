#include "Trie.h"

#include <iostream>

int main()
{
    TrieNode* root = getNewNode();
    insert(root, "apple");
    insert(root, "application");
    insert(root, "apply");
    insert(root, "book");
    insert(root, "box");

    char buffer[100];
    string result;
    findMinPrefixes(root, buffer, 0, result);

    cout << "Minimal Prefixes: " << result << endl;

    return 0;
}