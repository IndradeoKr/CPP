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

pair<bool,pair<int,int>> isBST(node<int>* root)
{
    //p.first = bool, p.second.first = minimum, p.second.second = maximum
    pair<bool,pair<int,int>> p;
    if(root == NULL)
    {
        p.first = true;
        p.second.first = INT_MAX;
        p.second.second = INT_MIN;
        return p;
    }
    pair<bool,pair<int,int>> Left = isBST(root->left);
    pair<bool,pair<int,int>> Right = isBST(root->right);
    int minimum = min(root->data, min(Left.second.first, Right.second.first));//minimum in tree.
    int maximum = max(root->data, max(Left.second.second, Right.second.second));//maximum in tree.
    bool ans = (root->data > Left.second.second) && (root->data <= Right.second.first) && Left.first && Right.first;
    p.first = ans;
    p.second.first = minimum;
    p.second.second = maximum;
    return p;
}

int main()
{
    node<int>* root = takeInput();
    print(root);
    pair<bool,pair<int,int>> p = isBST(root);
    cout << "Minimum in tree = " << p.second.first << endl;
    cout << "Maximum in tree = " << p.second.second << endl;
    if(p.first)
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}