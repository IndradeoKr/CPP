#include <bits/stdc++.h>
using namespace std;

template <typename T>
class bianryTree
{
public:
    T data;
    bianryTree *left;
    bianryTree *right;
    bianryTree(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~bianryTree()
    {
        delete left;
        delete right;
    }
};

/*bianryTree<int>* takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if(rootData == -1)
    {
        return NULL;
    }
    bianryTree<int>* root = new bianryTree<int>(rootData);
    bianryTree<int>* leftChild = takeInput();
    bianryTree<int>* rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}*/

bianryTree<int>* takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;
    if(rootData == -1)
    {
        return NULL;
    }
    bianryTree<int>* root = new bianryTree<int>(rootData);
    queue<bianryTree<int>*> pendingNode;
    pendingNode.push(root);
    while(pendingNode.size() != 0)
    {
        bianryTree<int>* front = pendingNode.front();
        pendingNode.pop();
        int leftChildData;
        cout << "Enter left child of " << front->data << endl;
        cin >> leftChildData;
        if(leftChildData != -1)
        {
            bianryTree<int>* child = new bianryTree<int>(leftChildData);
            front->left = child;
            pendingNode.push(child);
        }
        int rightChildData;
        cout << "Enter right child of " << front->data << endl;
        cin >> rightChildData;
        if(rightChildData != -1)
        {
            bianryTree<int>* child = new bianryTree<int>(rightChildData);
            front->right = child;
            pendingNode.push(child);
        }
    }
    return root;
}

/*void printTree(bianryTree<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data <<" : ";
    if(root->left != NULL)
    {
        cout << " L "<<root->left->data;
    }
    if(root->right != NULL)
    {
        cout << " R "<<root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}*/

void printTreeLevelWise(bianryTree<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    queue<bianryTree<int>*> pendingNode;
    pendingNode.push(root);
    while(pendingNode.size() != 0)
    {
        bianryTree<int>* front = pendingNode.front();
        pendingNode.pop();
        cout << front->data <<" : ";
        if(front->left != NULL)
        {
            cout << " L " <<front->left->data << ",";
            pendingNode.push(front->left);
        }
        if(front->right != NULL)
        {
            cout << " R " <<front->right->data;
            pendingNode.push(front->right);
        }
        cout << endl;
    }
}

int main()
{
    /*bianryTree<int>* root = new bianryTree<int>(1);
    bianryTree<int>* node1 = new bianryTree<int>(2);
    bianryTree<int>* node2 = new bianryTree<int>(3);
    root->left = node1;
    root->right = node2;
    */
    bianryTree<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);
    delete root;
    return 0;
}