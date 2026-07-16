#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums){
        int prev=0, curr=0;
        for(int n: nums){
            int temp=max(curr, prev+n);
            prev=curr; curr=temp;
        }
        return curr;
    }
};
