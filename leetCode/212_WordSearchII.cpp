#include <bits/stdc++.h>
using namespace std;

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    vector<string> vs;
    for (int i = 0; i < words.size(); i++)
    {
        if (exist(board, words[i]))
        {
            vs.push_back(words[i]);
        }
    }
    return vs;
}

bool exist(vector<vector<char>> &board, string &word)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (dfs(board, i, j, word))
            {
                return true;
            }
        }
    }
    return false;
}

bool dfs(vector<vector<char>> &board, int i, int j, string &word)
{
    if (!word.size())
        return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])
        return false;
    char c = board[i][j];
    board[i][j] = '*';
    string s = word.substr(1);
    bool ans = dfs(board, i - 1, j, s) || dfs(board, i + 1, j, s) || dfs(board, i, j - 1, s) || dfs(board, i, j + 1, s);
    board[i][j] = c;
    return ans;
}

int main()
{
    
    return 0;
}