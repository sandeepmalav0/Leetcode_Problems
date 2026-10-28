class Solution {
public:
    int m,n,ans;
    int solve(vector<vector<int>>& grid, int i,int j,int tar, vector<vector<vector<int>>>& dp){
        if(i==m || j==n)return 0;
        tar^=grid[i][j];
        if(i==m-1 && j==n-1){
            ans=min(ans,tar);
            return 0;
        }

        if(dp[i][j][tar])return 0;
        dp[i][j][tar] = 1;
        
        solve(grid,i,j+1,tar,dp);
        solve(grid,i+1,j,tar,dp);
        return 0;
    }
    int minCost(vector<vector<int>>& grid){
        m = grid.size();
        n = grid[0].size();
        ans = INT_MAX;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(1024,0)));
        solve(grid,0,0,0,dp);
        return ans;
    }
};