#pragma once

#include <string>
#include <vector>
#include <memory>

class TrieNode
{
public:
    std::vector<std::unique_ptr<TrieNode>> children;
    bool isEndOfWord;

    TrieNode();

    TrieNode* getChild(char c) const;
};

class Trie
{
public:
    std::unique_ptr<TrieNode> root_;

    Trie();

    void insert(const std::string& word);
    std::vector<std::string> search(const std::string& prefix);

private:
    void searchWords(TrieNode* node, const std::string& prefix, std::vector<std::string>& suggestions);
};