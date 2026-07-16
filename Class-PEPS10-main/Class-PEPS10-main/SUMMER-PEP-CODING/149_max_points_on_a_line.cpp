#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points){
        int n=points.size();
        if(n<=2) return n;
        int res=1;
        for(int i=0;i<n;i++){
            unordered_map<string,int> slopeCount;
            int duplicates=0, curMax=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                long long dx=points[j][0]-points[i][0];
                long long dy=points[j][1]-points[i][1];
                if(dx==0 && dy==0){ duplicates++; continue; }
                long long g=__gcd(llabs(dx),llabs(dy));
                dx/=g; dy/=g;
                if(dx<0){ dx=-dx; dy=-dy; }
                string key=to_string(dx)+"_"+to_string(dy);
                slopeCount[key]++;
                curMax=max(curMax, slopeCount[key]);
            }
            res=max(res, curMax+duplicates+1);
        }
        return res;
    }
};
