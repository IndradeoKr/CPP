#include <bits/stdc++.h>
using namespace std;
#include "B_tree.h"
#include "takeInputLvlWise.h"
#include "printTreeLvlWise.h"

int height(binaryTree<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ch1 = height(root->left);
    int ch2 = height(root->right);

    return max(ch1, ch2) + 1;
}

int diameter(binaryTree<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ch1 = height(root->left);
    int ch2 = height(root->right);

    int op1 = ch1 + ch2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1,max(op2, op3));
}

int main()
{
    binaryTree<int>* root = takeInputLvlWise();
    printTreeLvlWise(root);
    int D = diameter(root);
    cout << "Diameter of tree = " << D << endl;
    return 0;
}