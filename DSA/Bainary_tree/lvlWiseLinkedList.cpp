#include <bits/stdc++.h>
using namespace std;
#include "B_tree.h"
#include "takeInputLvlWise.h"
#include "print_L.h"

int main()
{
    binaryTree<int>* root = takeInputLvlWise();
    int ht = height(root);
    for(int i = 1; i <= ht; i++)
    {
        printl(root, i);
        cout << endl;
    }
    return 0;
}