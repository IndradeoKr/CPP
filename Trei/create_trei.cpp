#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertWord(TrieNode *root, string word)
    {
        if (!word.size())
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertWord(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertWord(root, word);
    }
    bool searchWord(TrieNode *root, string word)
    {
        if (!word.size())
        {
            if (root->isTerminal)
                return true;
        }
        int index = word[0] - 'a';
        bool ans = false;
        if (root->children[index] != NULL)
        {
            ans = searchWord(root->children[index], word.substr(1));
        }
        return ans;
    }
    bool searchWord(string word)
    {
        if (searchWord(root, word))
            return true;
        return false;
    }
};

int main()
{
    Trie t;
    t.insertWord("indradeo");
    t.insertWord("indra");
    t.insertWord("abcdefghijk");
    if (t.searchWord("indr"))
        cout << "true\n";
    else
        cout << "false\n";
    return 0;
}