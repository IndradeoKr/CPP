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

TreeNode<int> *sLargestElement(TreeNode<int> *root)
{
    bool flag = false;
    TreeNode<int> *first;
    TreeNode<int> *second;
    int Max = INT_MIN;
    int Min = INT_MIN;
    queue<TreeNode<int> *> pendingnode;
    pendingnode.push(root);
    if (Max < root->data)
    {
        flag = true;
        Min = Max;
        Max = root->data;
        first = root;
        second = root;
    }
    while (pendingnode.size() != 0)
    {
        TreeNode<int> *front = pendingnode.front();
        pendingnode.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            if (Max < front->children[i]->data)
            {
                flag = true;
                Min = Max;
                Max = front->children[i]->data;
                second = first;
                first = front->children[i];
            }
            pendingnode.push(front->children[i]);
        }
    }
    if (flag)
    {
        return second;
    }
    else
    {
        return NULL;
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
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    TreeNode<int>* ans = sLargestElement(root);
    if(ans == NULL)
    {
        cout << "There is no second largest element present in the tree\n";
    }
    else
    {
        cout << ans->data << endl;
    }
    return 0;
}