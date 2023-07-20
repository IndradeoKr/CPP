#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
                 1
                / \
               3   2
              / \ / \
             5  3 n  9

The maximum width exists in the third level with length 4 (5,3,null,9).
*/
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        int ans = 0;
        while (!q.empty())
        {
            int size = q.size();
            int mmin = q.front().second;
            int first, last;
            for (int i = 0; i < size; i++)
            {
                long ind = q.front().second - mmin;
                TreeNode *node = q.front().first;
                q.pop();
                if (i == 0)
                    first = ind;
                if (i == size - 1)
                    last = ind;
                if (node->left)
                    q.push({node->left, (ind * 2) + 1});//*****************
                if (node->right)
                    q.push({node->right, (ind * 2) + 2});//*****************
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};

int main()
{
    return 0;
}