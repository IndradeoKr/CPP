#include<bits/stdc++.h>
using namespace std;
void printTreeLvlWise(binaryTree<int>* root)
{
    if(root == NULL)
        return;
    queue<binaryTree<int>*> pending;
    pending.push(root);
    while(pending.size() != 0)
    {
        binaryTree<int>* front = pending.front();
        pending.pop();
        cout << front->data << ":";
        if(front->left != NULL)
        {
            cout << " L " <<front->left->data <<", ";
            pending.push(front->left);
        }
        if(front->right != NULL)
        {
            cout << " R " <<front->right->data;
            pending.push(front->right);
        }
        cout << endl;
    }
}