#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        unordered_set<int> s(nums.begin(), nums.end());
        int longest=0;
        for(int n: s){
            if(!s.count(n-1)){
                int len=1;
                while(s.count(n+len)) len++;
                longest=max(longest,len);
            }
        }
        return longest;
    }
};
