#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {} };
class BSTIterator {
    stack<TreeNode*> st;
    void pushLeft(TreeNode* node){ while(node){ st.push(node); node=node->left; } }
public:
    BSTIterator(TreeNode* root){ pushLeft(root); }
    int next(){
        TreeNode* node=st.top(); st.pop();
        pushLeft(node->right);
        return node->val;
    }
    bool hasNext(){ return !st.empty(); }
};
