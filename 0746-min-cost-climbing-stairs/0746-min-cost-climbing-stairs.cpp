class Solution {
public:
    int solve(int idx,vector<int>& cost,vector<int>& dp){
        if(idx==0 || idx==1){
            return cost[idx];
        }
        if(dp[idx] != -1)return dp[idx];
        int take = cost[idx]+solve(idx-1,cost,dp);
        int notake = cost[idx]+solve(idx-2,cost,dp);
        return dp[idx]=min(take,notake);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        int ans1=solve(n-1,cost,dp);
        int ans2=solve(n-2,cost,dp);
        return min(ans1,ans2);
    }
};