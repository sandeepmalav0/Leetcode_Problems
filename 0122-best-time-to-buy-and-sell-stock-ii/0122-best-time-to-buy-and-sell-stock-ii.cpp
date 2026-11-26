class Solution {
public:
    int n;
    int solve(vector<int>& arr,int idx,int buy,vector<vector<int>>& pro){
        if(idx==n)return 0;
        if(pro[idx][buy] != -1)return pro[idx][buy];

        int profit=0;
        if(buy){
            profit = max(-arr[idx]+solve(arr,idx+1,0,pro) , solve(arr,idx+1,1,pro));
        }else{
            profit = max(arr[idx]+solve(arr,idx+1,1,pro) , solve(arr,idx+1,0,pro));
        }
        return pro[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();

        // using memoization DP, take and non take functionality i use.
        // vector<vector<int>> dp(n,vector<int>(2, -1));
        // return solve(prices,0,1,dp);

        // using Tabulation DP
        vector<vector<int>> dp(n+1,vector<int>(2, 0));
        dp[n][1]=0;
        dp[n][0]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    dp[i][1] = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
                }else{
                    dp[i][0] = max(prices[i]+dp[i+1][1], dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};