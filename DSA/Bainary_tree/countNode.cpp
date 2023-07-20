#include <bits/stdc++.h>
using namespace std;
#include "B_tree.h"
#include "takeInputLvlWise.h"
#include "printTreeLvlWise.h"

int countNode(binaryTree<int>* root)
{
    if(root == NULL)
        return 0;
    int ans = 1;
    return 1 + countNode(root->left) + countNode(root->right);
}

int main()
{
    binaryTree<int>* root = takeInputLvlWise();
    printTreeLvlWise(root);
    cout << "Number of node : " << countNode(root);
    delete root;
    return 0;
}