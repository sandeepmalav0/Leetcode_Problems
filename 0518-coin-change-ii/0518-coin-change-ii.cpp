class Solution {
public:
    int helper(vector<int>& arr,int idx,int tar,vector<vector<int>>& dp){
        if(tar<0)return 0;
        if(tar==0)return 1;
        if(idx==0){
            return tar%arr[0]==0;
        }
        if(dp[idx][tar] != -1)return dp[idx][tar];
        int notake = helper(arr,idx-1,tar,dp);
        int take = helper(arr,idx,tar-arr[idx],dp);
        
        return dp[idx][tar]=notake+take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1, -1));
        int ans = helper(coins,n-1,amount,dp);
        return ans;
    }
};