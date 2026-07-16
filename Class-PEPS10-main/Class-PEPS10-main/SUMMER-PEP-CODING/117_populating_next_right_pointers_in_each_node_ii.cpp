#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val; Node *left, *right, *next;
    Node(): val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val): val(_val), left(nullptr), right(nullptr), next(nullptr) {}
};
class Solution {
public:
    // Same BFS approach works for general (non-perfect) binary trees too
    Node* connect(Node* root){
        if(!root) return root;
        queue<Node*> q; q.push(root);
        while(!q.empty()){
            int sz=q.size();
            Node* prev=nullptr;
            for(int i=0;i<sz;i++){
                Node* node=q.front(); q.pop();
                if(prev) prev->next=node;
                prev=node;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return root;
    }
};
