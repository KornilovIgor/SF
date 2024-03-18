#include "Trie.h"

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

void Trie::insert(const std::string& word)
{
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
}

std::vector<std::string> Trie::search(const std::string& prefix)
{
    std::vector<std::string> suggestions;
    TrieNode* curr = root_.get();
    for (char c : prefix)
    {
        curr = curr->getChild(c);
        if (curr == nullptr)
        {
            return suggestions;
        }
    }

    searchWords(curr, prefix, suggestions);
    return suggestions;
}

void Trie::searchWords(TrieNode* node, const std::string& prefix, std::vector<std::string>& suggestions)
{
    if (node->isEndOfWord)
    {
        suggestions.push_back(prefix);
    }
    for (int i = 0; i < 26; i++)
    {
        TrieNode* child = node->getChild('a' + i);
        if (child != nullptr)
        {
            searchWords(child, prefix + char('a' + i), suggestions);
        }
    }
}