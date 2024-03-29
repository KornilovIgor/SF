#include "Autocomplete.h"

#include <iostream>

TrieNode::TrieNode()
{
    children = std::vector<std::unique_ptr<TrieNode>>(26);
    isEndOfWord = false;
}

TrieNode* TrieNode::getChild(char c) const
{
    int index = c - 'a';
    if (index >= 0 && index < 26)
    {
        return children[index].get();
    }
    return nullptr;
}

Trie::Trie() : root_(std::make_unique<TrieNode>()) {}

bool Trie::insert(const std::string& word)
{
    for (char c : word)
    {
        if ((c - 'a') < 0 || (c - 'a') > 26)
        return false;
    }

    TrieNode* curr = root_.get();
    for (char c : word)
    {
        TrieNode* child = curr->getChild(c);
        if (child == nullptr)
        {
            child = new TrieNode();
            curr->children[c - 'a'] = std::unique_ptr<TrieNode>(child);
        }
        curr = child;
    }
    curr->isEndOfWord = true;
    return true;
}

std::vector<std::string> Trie::search(const std::string& prefix)
{
    std::vector<std::string> variants;
    TrieNode* curr = root_.get();
    for (char c : prefix)
    {
        curr = curr->getChild(c);
        if (curr == nullptr)
        {
            return variants;
        }
    }

    searchWords(curr, prefix, variants);
    return variants;
}

void Trie::searchWords(TrieNode* node, const std::string& prefix, std::vector<std::string>& variants)
{
    if (node->isEndOfWord)
    {
        variants.push_back(prefix);
    }
    for (int i = 0; i < 26; i++)
    {
        TrieNode* child = node->getChild('a' + i);
        if (child != nullptr)
        {
            searchWords(child, prefix + char('a' + i), variants);
        }
    }
}