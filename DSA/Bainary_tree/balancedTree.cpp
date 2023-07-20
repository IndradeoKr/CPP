#include <bits/stdc++.h>
using namespace std;
#include "B_tree.h"
#include "takeInputLvlWise.h"
#include "printTreeLvlWise.h"

//O(n^2) approx
// int height(binaryTree<int> *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     int ch1 = height(root->left);
//     int ch2 = height(root->right);

//     return max(ch1, ch2) + 1;
// }

// int balanced(binaryTree<int>* root)
// {
//     if(root == NULL)
//         return 0;
//     int left = height(root->left);
//     int right = height(root->right);
//     return abs(left-right);
// }


//O(n) approx
int balanced(binaryTree<int>* root)
{
    if(root == NULL) return 0;

    int left = balanced(root-left);
    if(left == -1) return -1;
    int right = balanced(root->right);
    if(right == -1) return -1;

    if(abs(left-right) > 1) return -1;

    return 1 + max(left,right);
}

int main ()
{
    binaryTree<int>* root = takeInputLvlWise();
    printTreeLvlWise(root);
    cout << balanced(root) << endl;
    if(balanced(root) != -1)
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}