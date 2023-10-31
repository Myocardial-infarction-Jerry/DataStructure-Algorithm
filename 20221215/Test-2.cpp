#include <bits/stdc++.h>
#include "BinaryNode.h"
using namespace std;

int leaves(const BinaryNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return leaves(root->left) + leaves(root->right);
}