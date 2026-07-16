#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {} };
class Solution {
public:
    int height(TreeNode* root, bool& balanced){
        if(!root) return 0;
        int lh = height(root->left, balanced);
        int rh = height(root->right, balanced);
        if(abs(lh-rh)>1) balanced=false;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root){
        bool balanced=true;
        height(root, balanced);
        return balanced;
    }
};
