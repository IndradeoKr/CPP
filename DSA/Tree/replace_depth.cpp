#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<int> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data:\n";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingnode;
    pendingnode.push(root);
    while (pendingnode.size() != 0)
    {
        TreeNode<int> *front = pendingnode.front();
        pendingnode.pop();
        int numChild;
        cout << "Enter number of childs of " << front->data << endl;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i + 1 << "th child data:\n";
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            pendingnode.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

void replaceDepth(TreeNode<int> *root, int depth)
{
    if (root == NULL)
    {
        return;
    }
    root->data = depth;
    for (int i = 0; i < root->children.size(); i++)
    {
        replaceDepth(root->children[i], depth + 1);
    }
}

void print(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pending;
    pending.push(root);
    cout << root->data << endl;
    while (pending.size() != 0)
    {
        TreeNode<int> *front = pending.front();
        pending.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << " ";
            pending.push(front->children[i]);
        }
        if (front->children.size() != 0)
            cout << endl;
    }
}

void printLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pendingnode;
    pendingnode.push(root);
    while (pendingnode.size() != 0)
    {
        TreeNode<int> *front = pendingnode.front();
        pendingnode.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            pendingnode.push(front->children[i]);
            cout << front->children[i]->data << ",";
        }
        cout << endl;
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    cout << endl;
    replaceDepth(root, 0);
    if (root != NULL)
    {
        print(root);
    }
    delete root;
    return 0;
}