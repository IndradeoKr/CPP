#include <bits/stdc++.h>
using namespace std;

struct node
{
    char c;
    int ends;
    string word;
    node *child[26];
};

node *getNode(char c)
{
    node *newNode = new node;
    newNode->c = c;
    newNode->ends = 0;
    newNode->word = "";
    for (int i = 0; i < 26; i++)
    {
        newNode->child[i] = NULL;
    }
    return newNode;
}
node *root = getNode('/');

void insert(string s)
{
    node *curr = root;
    int index, i = 0;
    while (s[i])
    {
        index = s[i] - 'a';
        if (curr->child[index] == NULL)
        {
            curr->child[index] = getNode(s[i]);
        }
        curr = curr->child[index];
        i += 1;
    }
    curr->ends += 1;
    curr->word = s;
}

int main()
{

    return 0;
}