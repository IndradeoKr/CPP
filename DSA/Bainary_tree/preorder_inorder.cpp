#include <bits/stdc++.h>
using namespace std;
#include "B_tree.h"
#include "print_L.h"

binaryTree<int>* createTreePreIn(vector<int> in, vector<int> pre, int s, int e)
{
    static int i = 0;
    //Base case
    if(s>e)
    {
        return NULL;
    }

    //Rec case
    binaryTree<int>* root = new binaryTree<int>(pre[i]);
    int index = -1;
    for(int j = s; j <= e; j++)
    {
        if(in[j] == pre[i])
        {
            index = j;
            break;
        }
    }
    i++;
    root->left = createTreePreIn(in, pre, s, index-1);
    root->right = createTreePreIn(in, pre, index+1, e);
    return root;
}

int main()
{
    vector<int> preorder;
    vector<int> inorder;
    int loop = 1;
    int size;
    cout << "Enter size\n";
    cin >> size;
    cout << "Enter preorder\n";
    for(int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        preorder.push_back(x);
    }
    cout << "Enter inorder\n";
    for(int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        inorder.push_back(x);
    }
    binaryTree<int>* root =  createTreePreIn(inorder, preorder,0,size-1);
    int ht = height(root);
    for (int i = 1; i <= ht; i++)
    {
        printl(root, i);
        cout << endl;
    }
    delete root;
    return 0;
}