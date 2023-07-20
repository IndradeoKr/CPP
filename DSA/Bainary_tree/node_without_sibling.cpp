#include <bits/stdc++.h>
using namespace std;
#include "B_tree.h"
#include "takeInputLvlWise.h"
#include "printTreeLvlWise.h"

void nodeWithoutSibling(binaryTree<int>* root)
{
    if(root == NULL)
        return;
    if(root->left != NULL && root->right != NULL)
    {
        nodeWithoutSibling(root->left);
        nodeWithoutSibling(root->right);
    }
    else if(root->left != NULL)
    {
        cout << root->left->data << " ";
        nodeWithoutSibling(root->left);
    }
    else if(root->right != NULL)
    {
        cout << root->right->data << " ";
        nodeWithoutSibling(root->right);
    }
}

int main()
{
    binaryTree<int>* root = takeInputLvlWise();
    printTreeLvlWise(root);
    cout << "Node wihout sibling\n";
    nodeWithoutSibling(root);
    return 0;
}