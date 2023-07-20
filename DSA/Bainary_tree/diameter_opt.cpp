#include <bits/stdc++.h>
using namespace std;
#include "B_tree.h"
#include "takeInputLvlWise.h"
#include "printTreeLvlWise.h"

pair<int,int> diameter(binaryTree<int>* root)
{
    //first == diameter, second == height
    pair<int, int> p;
    if(root == NULL)
    {
        p.first = p.second = 0;
        return p;
    }
    pair<int, int> left = diameter(root->left);
    pair<int, int> right = diameter(root->right);

    p.second = max(left.second,right.second)+1;
    p.first = max(left.second+right.second, max(left.first, right.first));
    return p;
}

int main()
{
    binaryTree<int>* root = takeInputLvlWise();
    printTreeLvlWise(root);
    pair<int,int> D = diameter(root);
    cout << "Diameter of tree = " << D.first << endl;
    cout << "Height of tree = " << D.second << endl;
    return 0;
}