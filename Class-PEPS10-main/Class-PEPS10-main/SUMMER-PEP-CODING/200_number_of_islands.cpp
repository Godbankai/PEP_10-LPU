#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        int m=grid.size(), n=grid[0].size();
        if(i<0||i>=m||j<0||j>=n||grid[i][j]!='1') return;
        grid[i][j]='0';
        dfs(grid,i+1,j); dfs(grid,i-1,j); dfs(grid,i,j+1); dfs(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid){
        int count=0;
        for(size_t i=0;i<grid.size();i++)
            for(size_t j=0;j<grid[0].size();j++)
                if(grid[i][j]=='1'){ count++; dfs(grid,i,j); }
        return count;
    }
};
