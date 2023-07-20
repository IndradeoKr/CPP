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

int count_node(TreeNode<int> *root, int num)
{
    static int count = 0;
    if (root == NULL)
    {
        return 0;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        count = count_node(root->children[i], num);
    }
    if (root->data > num)
        return count + 1;
    return count;
}

int main()
{
    int num;
    TreeNode<int> *root = takeInputLevelWise();

    printTreeLevelWise(root);

    cout << "Enter the number to find: " << endl;
    cin >> num;
    cout << count_node(root, num) << endl;

    delete root;
    return 0;
}