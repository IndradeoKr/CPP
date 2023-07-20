#include <bits/stdc++.h>
using namespace std;
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

void printl(binaryTree<int> *root, int height)
{
    if (root == NULL)
    {
        return;
    }
    if (height == 1)
    {
        cout << root->data << " ";
        return;
    }
    printl(root->left, height - 1);
    printl(root->right, height - 1);
    return;
}