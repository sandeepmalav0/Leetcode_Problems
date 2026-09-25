class Solution {
public:
    int solve(vector<int>& arr,int idx,int tar,vector<vector<int>>& dp){
        if (tar == 0) return 0;
        if(idx==0){
            if(tar%arr[0]==0)return tar/arr[0];
            return 1e9;
        }
        if(dp[idx][tar] != -1)return dp[idx][tar];
        int notake = solve(arr,idx-1,tar,dp);
        int take=1e9;
        if(tar >= arr[idx]){
            take = 1 + solve(arr,idx,tar-arr[idx],dp);
        }
        return dp[idx][tar]=min(notake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        // Using memoization DP
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1, -1));
        int ans = solve(coins,n-1,amount,dp);
        if(ans >= 1e9)return -1;
        return ans;
    }
};