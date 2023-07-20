#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode 
{
    public:
    T data;
    vector <TreeNode<T>*> children; //Here Vector is TreeNode means T type.

    TreeNode(T data)
    {
        this->data = data;
    }
};
