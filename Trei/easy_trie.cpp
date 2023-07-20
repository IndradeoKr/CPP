#include<bits/stdc++.h>
using namespace std;

class Node
{
private:
    Node* link[26];
    bool flag = false;
public:
    bool containKey(char ch)
    {
        return link[ch-'a'] != NULL;
    }

    void setKey(char ch, Node* node)
    {
        link[ch-'a'] = node;
    }

    Node* getKey(char ch)
    {
        return link[ch-'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};
class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!node->containKey(word[i]))
            {
                node->setKey(word[i], new Node());
            }
            node = node->getKey(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!node->containKey(word[i])) return false;
            node = node->getKey(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++)
        {
            if(!node->containKey(prefix[i])) return false;
            node = node->getKey(prefix[i]);
        }
        return true;
    }
};