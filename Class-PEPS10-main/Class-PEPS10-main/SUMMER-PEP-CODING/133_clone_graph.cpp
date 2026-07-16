#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val; vector<Node*> neighbors;
    Node(){ val=0; neighbors=vector<Node*>(); }
    Node(int _val){ val=_val; neighbors=vector<Node*>(); }
};
class Solution {
public:
    Node* cloneGraph(Node* node){
        if(!node) return nullptr;
        unordered_map<Node*, Node*> visited;
        queue<Node*> q; q.push(node);
        visited[node]=new Node(node->val);
        while(!q.empty()){
            Node* cur=q.front(); q.pop();
            for(auto nb: cur->neighbors){
                if(!visited.count(nb)){
                    visited[nb]=new Node(nb->val);
                    q.push(nb);
                }
                visited[cur]->neighbors.push_back(visited[nb]);
            }
        }
        return visited[node];
    }
};
