#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {} };
class Solution {
public:
    int maxDepth(TreeNode* root){ return root ? 1+max(maxDepth(root->left), maxDepth(root->right)) : 0; }
};
