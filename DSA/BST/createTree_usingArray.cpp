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

void print(node<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

node<int> *create(vector<int> v, int s, int e)
{
    if (v.size() == 0)
        return NULL;
    if (s <= e)
    {
        int mid = (s + e) / 2;
        node<int> *root = new node<int>(v[mid]);
        root->left = create(v, s, mid - 1);
        root->right = create(v, mid + 1, e);
        return root;
    }
    return NULL;
}

int main()
{
    vector<int> v;
    int n;
    cout << "Enter size of array\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    node<int> *root = create(v, 0, v.size() - 1);
    print(root);
    delete root;
    return 0;
}