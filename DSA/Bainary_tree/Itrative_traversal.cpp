#include <bits/stdc++.h>
using namespace std;
#include "B_tree.h"
#include "takeInputLvlWise.h"
#include "printTreeLvlWise.h"

void preorder(binaryTree<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    stack<binaryTree<int>*> st;
    st.push(root);
    while(!st.empty())
    {
        binaryTree<int>* temp = st.top();
        st.pop();
        cout << temp->data << " ";
        if(temp->right != NULL)
        {
            st.push(temp->right);
        }
        if(temp->left != NULL)
        {
            st.push(temp->left);
        }
    }
}

void inorder(binaryTree<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    stack<binaryTree<int>*> st;
    binaryTree<int>* temp = root;
    while(true)
    {
        if(temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if(st.empty()) break;
            temp = st.top();
            st.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }

}

/*using 2 stack
void postorder(binaryTree<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    stack<binaryTree<int>*> st1, st2;
    binaryTree<int>* temp = root;

    st1.push(temp);
    while(!st1.empty())
    {
        temp = st1.top();
        st1.pop();
        st2.push(temp);
        if(temp->left != NULL)
        {
            st1.push(temp->left);
        }
        if(temp->right != NULL)
        {
            st1.push(temp->right);
        }
    }

    while(!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}*/

//using 1 stack
void postorder(binaryTree<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    stack<binaryTree<int>*> st;
    binaryTree<int>* cur = root, *temp;

    while(cur != NULL || !st.empty())
    {
        if(cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            temp = st.top()->right;
            if(temp == NULL)
            {
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
                while(!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
            else
            {
                cur = temp;
            }
        }
    }
}

int main()
{
    binaryTree<int>* root = takeInputLvlWise();
    printTreeLvlWise(root);
    cout << "preorder: ";
    preorder(root);
    cout << endl;

    cout << "inorder: ";
    inorder(root);
    cout << endl;

    cout << "postorder: ";
    postorder(root);
    cout << endl;
    delete root;
    return 0;
}