#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {} };
class Solution {
public:
    void dfs(TreeNode* node, int cur, int& total){
        if(!node) return;
        cur=cur*10+node->val;
        if(!node->left && !node->right){ total+=cur; return; }
        dfs(node->left, cur, total);
        dfs(node->right, cur, total);
    }
    int sumNumbers(TreeNode* root){ int total=0; dfs(root,0,total); return total; }
};
