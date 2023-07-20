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

node<int> *takeInput()
{
    int rootData;
    cout << "Enter root data\n";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    node<int> *root = new node<int>(rootData);
    queue<node<int> *> p;
    p.push(root);
    while (p.size() != 0)
    {
        node<int> *f = p.front();
        p.pop();
        int leftChildData;
        cout << "Enter left child of " << f->data << endl;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            node<int> *Child = new node<int>(leftChildData);
            f->left = Child;
            p.push(Child);
        }
        int rightChildData;
        cout << "Enter right child of " << f->data << endl;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            node<int> *Child = new node<int>(rightChildData);
            f->right = Child;
            p.push(Child);
        }
    }
    return root;
}

vector<int> find(node<int> *root, int d)
{
    static vector<int> v;
    if (root == NULL)
        return v;
    if (root->data == d)
    {
        v.push_back(root->data);
        return v;
    }

    if (root->data > d)
    {
        find(root->left, d);
    }
    else
    {
        find(root->right, d);
    }
    v.push_back(root->data);
    return v;
}

int main()
{
    node<int> *root = takeInput();
    int d;
    cin >> d;
    vector<int> f = find(root, d);
    for (int i = 0; i < f.size(); i++)
    {
        cout << f.at(i) << " ";
    }
    cout << endl;
    return 0;
}