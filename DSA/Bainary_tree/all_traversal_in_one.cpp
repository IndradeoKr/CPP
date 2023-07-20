#include <bits/stdc++.h>
using namespace std;
#include "B_tree.h"
#include "takeInputLvlWise.h"
#include "printTreeLvlWise.h"

void Traversal(binaryTree<int>* root, vector<int> &preOrder, vector<int> &postOrder, vector<int> &inOrder)
{
    if(root == NULL) return;
    stack<pair<binaryTree<int>*,int>> st;
    st.push({root,1});

    while(!st.empty())
    {
        auto it = st.top();
        st.pop();

        if(it.second == 1)
        {
            preOrder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left != NULL) st.push({it.first->left,1});
        }

        else if(it.second == 2)
        {
            inOrder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right != NULL) st.push({it.first->right,1});
        }
        else
        {
            postOrder.push_back(it.first->data);
        }
    }
}

void print(vector<int> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    binaryTree<int>* root = takeInputLvlWise();
    printTreeLvlWise(root);

    vector<int> preOrder, postOrder, inOrder;

    Traversal(root,preOrder, postOrder, inOrder);

    cout << "preorder: ";
    print(preOrder);
    cout << endl;

    cout << "inorder: ";
    print(inOrder);
    cout << endl;

    cout << "postorder: ";
    print(postOrder);
    cout << endl;

    delete root;
    return 0;
}