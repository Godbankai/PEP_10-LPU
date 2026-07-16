#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {} };
class Solution {
public:
    TreeNode* build(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, unordered_map<int,int>& idx){
        if(is>ie) return nullptr;
        int rootVal = postorder[pe];
        TreeNode* root = new TreeNode(rootVal);
        int mid = idx[rootVal];
        int leftSize = mid - is;
        root->left = build(inorder, is, mid-1, postorder, ps, ps+leftSize-1, idx);
        root->right = build(inorder, mid+1, ie, postorder, ps+leftSize, pe-1, idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        unordered_map<int,int> idx;
        for(int i=0;i<(int)inorder.size();i++) idx[inorder[i]]=i;
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1, idx);
    }
};
