#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices){
        int n=prices.size();
        if(n==0||k==0) return 0;
        if(k>=n/2){
            int profit=0;
            for(int i=1;i<n;i++) if(prices[i]>prices[i-1]) profit+=prices[i]-prices[i-1];
            return profit;
        }
        vector<vector<int>> buy(k+1, vector<int>(n, 0)), sell(k+1, vector<int>(n,0));
        for(int i=1;i<=k;i++){
            buy[i][0]=-prices[0];
            for(int j=1;j<n;j++){
                buy[i][j]=max(buy[i][j-1], sell[i-1][j]-prices[j]);
                sell[i][j]=max(sell[i][j-1], buy[i][j-1]+prices[j]);
            }
        }
        return sell[k][n-1];
    }
};
