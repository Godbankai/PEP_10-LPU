#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {} };
class Solution {
public:
    void flatten(TreeNode* root){
        TreeNode* cur=root;
        while(cur){
            if(cur->left){
                TreeNode* rightmost = cur->left;
                while(rightmost->right) rightmost=rightmost->right;
                rightmost->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur=cur->right;
        }
    }
};
