#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {} };
class Solution {
public:
    TreeNode* build(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie, unordered_map<int,int>& idx){
        if(ps>pe) return nullptr;
        int rootVal = preorder[ps];
        TreeNode* root = new TreeNode(rootVal);
        int mid = idx[rootVal];
        int leftSize = mid - is;
        root->left = build(preorder, ps+1, ps+leftSize, inorder, is, mid-1, idx);
        root->right = build(preorder, ps+leftSize+1, pe, inorder, mid+1, ie, idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        unordered_map<int,int> idx;
        for(int i=0;i<(int)inorder.size();i++) idx[inorder[i]]=i;
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1, idx);
    }
};
