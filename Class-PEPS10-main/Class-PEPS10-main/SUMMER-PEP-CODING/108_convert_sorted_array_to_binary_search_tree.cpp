#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {} };
class Solution {
public:
    TreeNode* helper(vector<int>& nums, int l, int r){
        if(l>r) return nullptr;
        int mid=l+(r-l)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, l, mid-1);
        root->right = helper(nums, mid+1, r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums){ return helper(nums,0,nums.size()-1); }
};
