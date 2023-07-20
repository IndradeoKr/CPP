#include <bits/stdc++.h>
using namespace std;
#include "B_tree.h"
#include "takeInputLvlWise.h"
#include "printTreeLvlWise.h"

int isNodePresent(binaryTree<int>* root, int x)
{
    if(root == NULL)
    {
        return 0;
    }
    queue<binaryTree<int>*> pending;
    pending.push(root);
    while(pending.size() != 0)
    {
        binaryTree<int>* front = pending.front();
        pending.pop();
        if(front->data == x)
        {
            return 1;
        }
        if(front->left != NULL)
        {
            pending.push(front->left);
        }
        if(front->right != NULL)
        {
            pending.push(front->right);
        }
    }
    return 0;
}

int main()
{
    binaryTree<int>* root = takeInputLvlWise();
    printTreeLvlWise(root);
    int x;
    cout << "Enter data of a node which you want to find: " << endl;
    cin >> x;
    if(isNodePresent(root, x))
        cout << "True\n";
    else
        cout << "False\n";
    delete root;
    return 0;
}