#include <bits/stdc++.h>
// #include "treeNode.h"
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children; // Here Vector is TreeNode means T type.

    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode() // To delete all the dynamically allocates nodes.
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
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter num of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTreeLevelWise(TreeNode<int> *root) // pre order.
{
    if (root == NULL)
    {
        return;
    }

    queue<TreeNode<int> *> pendigNode;
    pendigNode.push(root);
    while (pendigNode.size() != 0)
    {
        TreeNode<int> *front = pendigNode.front();
        pendigNode.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            pendigNode.push(front->children[i]);
            cout << front->children[i]->data << ",";
        }
        cout << endl;
    }
}

bool to_find(TreeNode<int> *root, int num)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == num)
        return true;

    // for (int i = 0; i < root->children.size(); i++)
    // {
    //     if (root->children[i]->data == num)
    //         return true;
    // }

    for (int i = 0; i < root->children.size(); i++)
    {
        if (root->children[i]->data == num)
            return true;
        to_find(root->children[i], num);
    }
    return false;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);

    int num;
    cout << "Enter number to find" << endl;
    cin >> num;
    bool ans = to_find(root, num);
    if (ans)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    delete root;
    return 0;
}