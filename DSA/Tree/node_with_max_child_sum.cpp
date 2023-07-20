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

    queue<TreeNode<int> *> pendingNode;
    pendingNode.push(root);
    while (pendingNode.size() != 0)
    {
        TreeNode<int> *front = pendingNode.front();
        pendingNode.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            pendingNode.push(front->children[i]);
            cout << front->children[i]->data << ",";
        }
        cout << endl;
    }
}

void child_sum(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    int sum;
    int temp1, temp2;
    TreeNode<int> *ans;
    queue<TreeNode<int> *> pending;
    pending.push(root);

    TreeNode<int> *ads = pending.front();
    sum = pending.front()->data;
    pending.pop();
    for (int i = 0; i < ads->children.size(); i++)
    {
        pending.push(ads->children[i]);
        sum = sum + ads->children[i]->data;
    }
    temp1 = sum;
    while (pending.size() != 0)
    {
        sum = 0;
        TreeNode<int> *front = pending.front();
        sum = pending.front()->data;
        pending.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            pending.push(front->children[i]);
            sum = sum + front->children[i]->data;
        }
        if (sum > temp1)
        {
            ans = front;
            ads = front;
        }
        else
        {
            ans = ads;
        }
        temp1 = max(temp1, sum);
    }
    cout << ans->data << endl;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    printTreeLevelWise(root);

    child_sum(root);

    delete root;
    return 0;
}