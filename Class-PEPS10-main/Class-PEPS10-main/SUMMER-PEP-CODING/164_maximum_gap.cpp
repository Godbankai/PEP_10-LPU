#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums){
        int n=nums.size();
        if(n<2) return 0;
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        if(mx==mn) return 0;
        int bucketSize=max(1,(mx-mn)/(n-1));
        int bucketNum=(mx-mn)/bucketSize+1;
        vector<pair<int,int>> buckets(bucketNum,{INT_MAX,INT_MIN});
        for(int x: nums){
            int idx=(x-mn)/bucketSize;
            buckets[idx].first=min(buckets[idx].first,x);
            buckets[idx].second=max(buckets[idx].second,x);
        }
        int result=0, prevMax=mn;
        for(auto& b: buckets){
            if(b.first==INT_MAX) continue;
            result=max(result, b.first-prevMax);
            prevMax=b.second;
        }
        return result;
    }
};
