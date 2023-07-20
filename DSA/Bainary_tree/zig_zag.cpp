#include <bits/stdc++.h>
using namespace std;
template <typename T>
class binaryTree
{
    public:
        T data;
        binaryTree* left;
        binaryTree* right;
    binaryTree(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~binaryTree()
    {
        delete left;
        delete right;
    }
};

binaryTree<int>* takeInputLvlWise()
{
    int rootData;
    cout << "Enter root data\n";
    cin >> rootData;
    if(rootData == -1)
    {
        return NULL;
    }
    binaryTree<int>*root = new binaryTree<int>(rootData);
    queue<binaryTree<int>*> pending;
    pending.push(root);
    while(pending.size() != 0)
    {
        binaryTree<int>* front = pending.front();
        pending.pop();
        int leftChild;
        cout << "Enter left child data of " << front->data << endl;
        cin >> leftChild;
        if(leftChild != -1)
        {
            binaryTree<int>* child = new binaryTree<int>(leftChild);
            front->left = child;
            pending.push(child);
        }
        int rightChild;
        cout << "Enter right child data of " << front->data << endl;
        cin >> rightChild;
        if(rightChild != -1)
        {
            binaryTree<int>* child = new binaryTree<int>(rightChild);
            front->right = child;
            pending.push(child);
        }
    }
    return root;
}

void printTreeLvlWise(binaryTree<int>* root)
{
    if(root == NULL)
        return;
    queue<binaryTree<int>*> pending;
    pending.push(root);
    while(pending.size() != 0)
    {
        binaryTree<int>* front = pending.front();
        pending.pop();
        cout << front->data << ":";
        if(front->left != NULL)
        {
            cout << " L " <<front->left->data <<", ";
            pending.push(front->left);
        }
        if(front->right != NULL)
        {
            cout << " R " <<front->right->data;
            pending.push(front->right);
        }
        cout << endl;
    }
}

void zigZag(binaryTree<int> *root)
{
    // int f1 = 1;
    // int f2 = 0;
    int lvl = 1;
    if (root == NULL)
        return;
    stack<binaryTree<int> *> st1;
    stack<binaryTree<int> *> st2;
    st1.push(root);
    while (st1.size() != 0 || st2.size() != 0)
    {
        if (st1.size() != 0 && lvl % 2 !=0)
        {
            binaryTree<int> *f = st1.top();
            st1.pop();
            cout << f->data << " ";
            if (f->left != NULL)
            {
                st2.push(f->left);
            }
            if (f->right != NULL)
            {
                st2.push(f->right);
            }
            if (st1.size() == 0)
            {
                lvl++;
                cout << endl;
            }
        }
        else if(st2.size() != 0 && lvl % 2 == 0)
        {
            binaryTree<int> *f = st2.top();
            st2.pop();
            cout << f->data << " ";
            if (f->right != NULL)
            {
                st1.push(f->right);
            }
            if (f->left != NULL)
            {
                st1.push(f->left);
            }
            if (st2.size() == 0)
            {
                lvl++;
                cout << endl;
            }
        }
    }
}

int main()
{
    binaryTree<int> *root = takeInputLvlWise();
    printTreeLvlWise(root);
    cout << "Zig Zag\n";
    zigZag(root);
    return 0;
}