#include <bits/stdc++.h>
using namespace std;
#include "B_tree.h"
#include "takeInputLvlWise.h"
#include "printTreeLvlWise.h"

int sumOfNode(binaryTree<int> *root)
{
    if (root == NULL)
        return 0;
    int left = sumOfNode(root->left);
    int right = sumOfNode(root->right);
    int sum = root->data;
    return sum + left + right;
}

int main()
{
    binaryTree<int> *root = takeInputLvlWise();
    printTreeLvlWise(root);
    int sum = sumOfNode(root);
    cout << "Sum of all nodes = " << sum << endl;
    return 0;
}