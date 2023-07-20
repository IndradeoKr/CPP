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
    ~TreeNode()//To delete all the dynamically allocates nodes.
    {
        for(int i = 0; i < children.size(); i++)
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

// TreeNode<int>* takeInput()
// {
//     int rootData;
//     cout << "Enter data" << endl;
//     cin >> rootData;
//     TreeNode<int>* root = new TreeNode<int>(rootData);

//     int n;
//     cout << "Enter num of children of " << rootData << endl;
//     cin >> n;
//     for(int i = 0; i < n; i++)
//     {
//         TreeNode<int>* child = takeInput();
//         root->children.push_back(child);
//     }
//     return root;
// }

void printTreeLevelWise(TreeNode<int> *root)//pre order. 
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

// void printTree(TreeNode<int>* root)
// {
//     if(root == NULL)// This is not a base case. Its a edge case.
//     {
//         return;
//     }
//     cout << root->data <<":";
//     for(int i = 0; i < root->children.size(); i++)
//     {
//         cout << root->children[i]->data << ",";
//     }
//     cout << endl;
//     for(int i = 0; i < root->children.size(); i++)
//     {
//         printTree(root->children[i]);
//     }
// }

int numNodes(TreeNode<int> *root) // it count number of node.
{
    if(root == NULL)
    {
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

int sumOfData(TreeNode<int> *root) // It return the sum all nodes data.
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += sumOfData(root->children[i]);
    }
    return ans;
}

int largestNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        int x = largestNode(root->children[i]);
        if (x > ans)
        {
            ans = x;
        }
    }
    return ans;
}

int height(TreeNode<int> *root)
{
    if(root == NULL)
    {
        return 0;
    }
    int ht = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int ch = height(root->children[i]);
        ht = max(ch, ht);
    }
    ht += 1;
    return ht;
}

void printAtLevel(TreeNode<int> *root, int k)
{
    if(root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout <<root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevel(root->children[i], k - 1);
    }
}

int leafNode(TreeNode<int>* root)
{
    static int count = 0;
    if(root == NULL)
    {
        return 0;
    }
    if(root->children.size() == 0)
    {
        count++;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        leafNode(root->children[i]);
    }
    return count;
}

void preorder(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data << " " ;
    for(int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    for(int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }
    cout << root->data << " " ;
}

// void deleteTree(TreeNode<int>* root)
// {
//     for(int i = 0; i < root->children.size(); i++)
//     {
//         deleteTree(root->children[i]);
//     }
//     delete root;
// }

int main()
{
    // TreeNode<int>* root = new TreeNode<int>(1);//(1)-> This is the value of root.
    // TreeNode<int>* node1 = new TreeNode<int>(2);//(2)-> This is the value of node1.
    // TreeNode<int>* node2 = new TreeNode<int>(3);//(3)-> This is the value of node2.
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    int k;
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    cout << "Enter level: "<< endl;
    cin >> k;
    cout << endl;
    printAtLevel(root, k);
    cout << endl;
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    cout << "Number of all nodes: " << numNodes(root) << endl;
    cout << "Sum of all nodes data: " << sumOfData(root) << endl;
    cout << "Largest node: " << largestNode(root) << endl;
    cout << "Height of tree: " << height(root) << endl;
    cout << "Number of leaf nodes: " << leafNode(root) << endl;
    delete root;
    return 0;
}