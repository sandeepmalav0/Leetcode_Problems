class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        // Using Tabulation DP
        vector<vector<int>> dp(n,vector<int>(amount+1, 0));
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0)dp[0][t]=t/coins[0];
            else dp[0][t]=1e9;
        }
        for(int idx=1;idx<n;idx++){
            for(int tar=0;tar<=amount;tar++){
                int notake=dp[idx-1][tar];
                int take = 1e9;
                if(tar >= coins[idx]){
                    take = 1 + dp[idx][tar-coins[idx]];
                }
                dp[idx][tar] = min(notake,take);
            }
        }
        return dp[n-1][amount]>=1e9?-1:dp[n-1][amount];
    }
};