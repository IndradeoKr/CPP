#include <bits/stdc++.h>
using namespace std;
#include "B_tree.h"
#include "takeInputLvlWise.h"
#include "printTreeLvlWise.h"

void replace(binaryTree<int>* root)
{
    if(root == NULL)
        return;
    if(root->left != NULL && root->right != NULL)
    {
        root->data = root->left->data + root->right->data;
    }
    else if(root->left != NULL)
    {
        root->data = root->left->data;
    }
    else if(root->right != NULL)
    {
        root->data = root->right->data;
    }
    replace(root->left);
    replace(root->right);
}

int main()
{
    binaryTree<int>* root = takeInputLvlWise();
    printTreeLvlWise(root);
    replace(root);
    cout << "After replace\n";
    printTreeLvlWise(root);
    return 0;
}