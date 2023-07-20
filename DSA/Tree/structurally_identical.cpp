#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
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
    cout << "Enter data:\n";
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

bool check(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    queue<TreeNode<int> *> node1;
    queue<TreeNode<int> *> node2;
    node1.push(root1);
    node2.push(root2);
    while (node1.size() != 0 || node2.size() != 0)
    {
        TreeNode<int> *front1 = node1.front();
        TreeNode<int> *front2 = node2.front();
        node1.pop();
        node2.pop();
        if (front1->data != front2->data)
        {
            return false;
        }
        else if (front1->children.size() != front2->children.size())
        {
            return false;
        }
        else
        {
            for (int i = 0; i < front1->children.size(); i++)
            {
                if (front1->children[i]->data != front2->children[i]->data)
                {
                    return false;
                }
                node1.push(front1->children[i]);
                node2.push(front2->children[i]);
            }
        }
    }
    return true;
}

void printTreeLevelWise(TreeNode<int> *root)
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
int main()
{
    cout << "\nFrist Tree\n";
    TreeNode<int> *root1 = takeInputLevelWise();
    cout << "\nSecond Tree\n";
    TreeNode<int> *root2 = takeInputLevelWise();
    cout << "\nFrist Tree\n";
    printTreeLevelWise(root1);
    cout << "\nSecond Tree\n";
    printTreeLevelWise(root2);

    if (check(root1, root2))
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    }
    delete root1;
    delete root1;
    return 0;
}