#include<bits/stdc++.h>
using namespace std;
binaryTree<int>* takeInputLvlWise()
{
    int rootData;
    cout << "Enter root data\n";
    cin >> rootData;
    if(rootData == -1)
    {
        return NULL;
    }
    binaryTree<int>*root = new binaryTree<int>(rootData);
    queue<binaryTree<int>*> pending;
    pending.push(root);
    while(pending.size() != 0)
    {
        binaryTree<int>* front = pending.front();
        pending.pop();
        int leftChild;
        cout << "Enter left child data of " << front->data << endl;
        cin >> leftChild;
        if(leftChild != -1)
        {
            binaryTree<int>* child = new binaryTree<int>(leftChild);
            front->left = child;
            pending.push(child);
        }
        int rightChild;
        cout << "Enter right child data of " << front->data << endl;
        cin >> rightChild;
        if(rightChild != -1)
        {
            binaryTree<int>* child = new binaryTree<int>(rightChild);
            front->right = child;
            pending.push(child);
        }
    }
    return root;
}