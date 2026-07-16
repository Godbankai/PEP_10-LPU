#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {} };
class Solution {
public:
    void dfs(TreeNode* node, int target, vector<int>& path, vector<vector<int>>& res){
        if(!node) return;
        path.push_back(node->val);
        if(!node->left && !node->right && node->val==target) res.push_back(path);
        else {
            dfs(node->left, target-node->val, path, res);
            dfs(node->right, target-node->val, path, res);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum){
        vector<vector<int>> res; vector<int> path;
        dfs(root, targetSum, path, res);
        return res;
    }
};
