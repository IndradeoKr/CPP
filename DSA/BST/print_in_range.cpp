#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node
{
    public:
        T data;
        node* left;
        node* right;
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
        return NULL;
    node<int>* root = new node<int>(rootData);
    queue<node<int>*> q;
    q.push(root);
    while(q.size() != 0)
    {
        node<int>* f = q.front();
        q.pop();
        int leftChildData;
        cout << "Enter left child of " << f->data << endl;
        cin >> leftChildData;
        if(leftChildData != -1)
        {
            node<int>* child = new node<int>(leftChildData);
            q.push(child);
            f->left = child;
        }

        int rightChildData;
        cout << "Enter left child of " << f->data << endl;
        cin >> rightChildData;
        if(rightChildData != -1)
        {
            node<int>* child = new node<int>(rightChildData);
            q.push(child);
            f->right = child;
        }
    }
    return root;
}

void print(node<int>* root)
{
    queue<node<int>*> p;
    p.push(root);
    while(p.size() != 0)
    {
        node<int>* f = p.front();
        p.pop();
        cout << f->data << " : ";
        if(f->left != NULL)
        {
            cout << " L " << f->left->data << ",";
            p.push(f->left);
        }
        if(f->right != NULL)
        {
            cout << " R " << f->right->data << ",";
            p.push(f->right);
        }
        cout << endl;
    }
}

void print_in_range(node<int>* root, int s, int e, vector<int> &t)
{
    if(root == NULL)
        return;
    if(root->data < e)
    {
        print_in_range(root->right, s, e, t);
    }
    if(root->data > s)
    {
        print_in_range(root->left, s, e, t);
    }
    if(root->data >= s && root->data <= e)
    {
        t.push_back(root->data);
    }
}

int main()
{
    node<int>* root = takeInput();
    print(root);
    int s, e;
    cout << "Enter range: ";
    cin >> s >> e;
    vector<int> t;
    print_in_range(root, s, e, t);
    sort(t.begin(), t.end());
    for(auto it : t)
    {
        cout << it << " ";
    }
    cout << endl;
    delete root;
    return 0;
}