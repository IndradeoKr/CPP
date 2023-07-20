#include <bits/stdc++.h>
using namespace std;
#include "B_tree.h"
#include "takeInputLvlWise.h"
#include "printTreeLvlWise.h"

int height(binaryTree<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }
    
    int ch1 = height(root->left);
    int ch2 = height(root->right);

    return max(ch1,ch2) + 1;
}

int main()
{
    binaryTree<int>* root = takeInputLvlWise();
    printTreeLvlWise(root);
    cout << "Height of tree " << height(root) << endl;
    return 0;
}