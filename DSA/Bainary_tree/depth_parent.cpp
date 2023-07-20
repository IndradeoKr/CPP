#include <bits/stdc++.h>
using namespace std;
#include "B_tree.h"
#include "takeInputLvlWise.h"
#include "printTreeLvlWise.h"
void height(binaryTree<int>* root, int d, int p, unordered_map<int, pair<int, int>> &m)
{
    if (root == NULL)
        return;
    m[root->data] = {d, p};
    height(root->left, d + 1, root->data, m);
    height(root->right, d + 1, root->data, m);
}
int main()
{
    binaryTree<int>* root = takeInputLvlWise();
    unordered_map<int,pair<int,int>> m;
    printTreeLvlWise(root);
    height(root,0,-1,m);
    for(auto i:m) cout << "root->data = " << i.first << " depth = " << i.second.first << " parent = " << i.second.second << endl;
    return 0;
}