#include "TreeNode.h"
#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void dfs(TreeNode *root, bool dir, int k)
{
    if (!root)
        return;
    ans = max(ans, k);
    if (dir)
    {
        dfs(root->left, 1, 1);
        dfs(root->right, 0, k + 1);
    }
    else
    {
        dfs(root->left, 1, k + 1);
        dfs(root->right, 0, 1);
    }
    return;
}

int longestZigZag(TreeNode *root)
{
    ans = 0;
    dfs(root->left, 1, 1);
    dfs(root->right, 0, 1);
    return ans;
}