#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    vector<TrieNode*>children;
    bool isTerminal;
    TrieNode(char data)
    {
        this->data = data;
        children = vector<TrieNode*>(26, NULL);
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
    void insert(TrieNode *root, string word)
    {
        if (!word.size())
        {
            root->isTerminal = true;
            return;
        }
        int index;
        if (word[0] >= 97 && word[0] <= 122)
            index = word[0] - 'a';
        else
            index = word[0] - 'A';
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
        insert(child, word.substr(1));
    }
    void insert(string word)
    {
        insert(root, word);
    }
    bool search(TrieNode *root, vector<vector<char>> &board, int i, int j, int r, int c)
    {
        if (root->isTerminal)
        {
            return true;
        }
        if (i < 0 || i >= c || j < 0 || j >= r)
            return false;
        int index;
        if (board[i][j] >= 97 && board[i][j] <= 122)
            index = board[i][j] - 'a';
        else
            index = board[i][j] - 'A';
        if (root->children[index] == NULL)
            return false;
        char ch = board[i][j];
        board[i][j] = '*';
        bool ans = search(root->children[index], board, i - 1, j, r, c) || search(root->children[index], board, i + 1, j, r, c) || search(root->children[index], board, i, j - 1, r, c) || search(root->children[index], board, i, j + 1, r, c);
        board[i][j] = ch;
        return ans;
    }
    bool search(vector<vector<char>> &board, int i, int j, int r, int c)
    {
        if (search(root, board, i, j, r, c))
            return true;
        return false;
    }
};

bool exist(vector<vector<char>> &board, string word)
{
    int c = board.size();
    int r = board[0].size();
    Trie t;
    TrieNode *q;
    t.insert(word);
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (t.search(board, i, j, r, c))
                return true;
        }
    }

    return false;
}

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C'}, {'H', 'G', 'D'}, {'I', 'F', 'E'}};
    string word = "ABCDEFGHI";
    if (exist(board, word))
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}