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

void inorder(node<int>* curr, node<int>* &pre)
{
    if(curr == NULL)
        return;
    inorder(curr->left, pre);
    pre->left = NULL;
    pre->right = curr;
    pre = curr;
    inorder(curr->right, pre);
}

node<int>* LL(node<int>* root)
{
    if(root == NULL)
        return NULL;
    node<int>* dummy = new node<int>(-1);
    node<int>* pre = dummy;
    inorder(root, pre);
    pre->left = NULL;
    pre->right = NULL;
    node<int>* ans = dummy->right;
    return ans;
}

void print(node<int>* root)
{
    node<int>* temp = root;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
}

int main()
{
    node<int>* root = takeInput();
    root = LL(root);
    print(root);
    return 0;
}