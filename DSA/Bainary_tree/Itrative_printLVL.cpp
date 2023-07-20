#include <bits/stdc++.h>
using namespace std;
#include "B_tree.h"
#include "takeInputLvlWise.h"
#include "printTreeLvlWise.h"

void bfs(binaryTree<int> *root)
{
    queue<binaryTree<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        binaryTree<int> *front = q.front();
        if (front == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            q.pop();
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
}

int main()
{
    binaryTree<int> *root = takeInputLvlWise();
    printTreeLvlWise(root);
    cout << "Level Order Traversal\n";
    bfs(root);
    return 0;
}