#include <bits/stdc++.h>
using namespace std;
#include "B_tree.h"
#include "takeInputLvlWise.h"
#include "printTreeLvlWise.h"
#include "print_L.h"

binaryTree<int>* removeLeafNode(binaryTree<int>* root)
{
    if(root == NULL)
        return NULL;
    if(root->left == NULL && root->right == NULL)
    {
        return NULL;
    }
    root->left = removeLeafNode(root->left);
    root->right = removeLeafNode(root->right);
    return root;
}

int main()
{
    binaryTree<int>* root = takeInputLvlWise();
    printTreeLvlWise(root);
    root = removeLeafNode(root);
    cout << "After\n";
    int ht = height(root);
    for(int i = 1; i <= ht; i++)
    {
        printl(root, i);
        cout << endl;
    }
    
    return 0;
}