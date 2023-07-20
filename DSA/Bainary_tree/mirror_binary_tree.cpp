#include <bits/stdc++.h>
using namespace std;
#include "B_tree.h"
#include "takeInputLvlWise.h"
#include "printTreeLvlWise.h"

void mirror(binaryTree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

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

int main()
{
    binaryTree<int> *root = takeInputLvlWise();
    int ht = height(root);
    printTreeLvlWise(root);
    cout << "After swaping\n";
    mirror(root);
    for (int i = 1; i <= ht; i++)
    {
        printl(root, i);
        cout << endl;
    }
    delete root;
    return 0;
}