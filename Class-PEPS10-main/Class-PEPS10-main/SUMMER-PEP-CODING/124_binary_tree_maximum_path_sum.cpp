#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {} };
class Solution {
public:
    int maxSum=INT_MIN;
    int helper(TreeNode* node){
        if(!node) return 0;
        int left=max(0, helper(node->left));
        int right=max(0, helper(node->right));
        maxSum=max(maxSum, node->val+left+right);
        return node->val+max(left,right);
    }
    int maxPathSum(TreeNode* root){ maxSum=INT_MIN; helper(root); return maxSum; }
};
