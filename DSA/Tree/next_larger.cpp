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
    int rootdata;
    cout << "Enter root data:\n";
    cin >> rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
    queue<TreeNode<int> *> pendingnode;
    pendingnode.push(root);
    while (pendingnode.size() != 0)
    {
        TreeNode<int> *front = pendingnode.front();
        pendingnode.pop();
        int numChild;
        cout << "Enter number of children of " << front->data << endl;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter child data :\n";
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingnode.push(child);
        }
    }
    return root;
}

TreeNode<int>* nextLarger(TreeNode<int>* root, int n)
{
    if(root == NULL)
    {
        return root;
    }
    bool flag = false;
    TreeNode<int>* first;
    TreeNode<int>* second;
    queue<TreeNode<int>*> pending;
    pending.push(root);
    int temp1 = INT_MAX;
    int temp2 = INT_MAX;
    if(root->data > n)
    {
        temp1 = root->data - n;
        first = root;
        flag = true;
    }
    while(pending.size() != 0)
    {
        TreeNode<int>* front = pending.front();
        pending.pop();
        for(int i = 0; i < front->children.size(); i++)
        {
            pending.push(front->children[i]);
            if(front->children[i]->data > n)
            {
                temp2 = front->children[i]->data - n;
                second = front->children[i];
            }
            if(temp2 < temp1)
            {
                temp1 = temp2;
                first = front->children[i];
                flag = true;
            }
        }
    }
    if(flag)
    {
        return first;
    }
    else
    {
        return NULL;
    }
}

void printLevelWise(TreeNode<int> *root)
{
    if(root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pendingnode;
    pendingnode.push(root);
    while(pendingnode.size() != 0)
    {
        TreeNode<int> *front = pendingnode.front();
        pendingnode.pop();
        cout << front->data << ":";
        for(int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
            pendingnode.push(front->children[i]);
        }
        cout << endl;
    }
}

int main()
{
    int n;
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans;
    printLevelWise(root);
    cout << endl;
    cout << "Enter number to find just greater:\n";
    cin >> n;
    ans = nextLarger(root, n);
    if(ans == NULL)
    {
        cout << "No number is present just greter than " << n << endl;
    }
    else
    {
        cout << ans->data;
    }
    delete root;
    delete ans;
    return 0;
}