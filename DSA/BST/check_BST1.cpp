#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node
{
    public:
        T data;
        node *left;
        node *right;
    node(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~node()
    {
        delete left;
        delete right;
    }
};

node<int>* takeInput()
{
    int rootData;
    cout << "Enter root data\n";
    cin >> rootData;
    if(rootData == -1)
    {
        return NULL;
    }
    node<int>* root = new node<int>(rootData);
    queue<node<int>*> p;
    p.push(root);
    while(p.size() != 0)
    {
        node<int>* f = p.front();
        p.pop();
        int leftChildData;
        cout << "Enter left child of " << f->data << endl;
        cin >> leftChildData;
        if(leftChildData != -1)
        {
            node<int>* Child = new node<int>(leftChildData);
            f->left = Child;
            p.push(Child);
        }
        int rightChildData;
        cout << "Enter right child of " << f->data << endl;
        cin >> rightChildData;
        if(rightChildData != -1)
        {
            node<int>* Child = new node<int>(rightChildData);
            f->right = Child;
            p.push(Child);
        }
    }
    return root;
}

void print(node<int>* root)
{
    if(root == NULL)
        return;
    queue<node<int>*> q;
    q.push(root);
    while(q.size() != 0)
    {
        node<int>* f = q.front();
        q.pop();
        cout << f->data << " : ";
        if(f->left != NULL)
        {
            cout << " L " <<f->left->data << ",";
            q.push(f->left);
        }
        if(f->right != NULL)
        {
            cout << " R " <<f->right->data;
            q.push(f->right);
        }
        cout << endl;
    }
}

int maximum(node<int>* root)
{
    if(root == NULL)
        return INT_MIN;
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(node<int>* root)
{
    if(root == NULL)
        return INT_MAX;
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(node<int>* root)
{
    if(root == NULL)
        return true;
    int leftmax = maximum(root->left);
    int rightmin = minimum(root->right);
    bool output = (root->data > leftmax) && (root->data <= rightmin) && isBST(root->left) && isBST(root->right);
    return output;
}

int main()
{
    node<int>* root = takeInput();
    print(root);
    cout << isBST(root) << endl;

    return 0;
}