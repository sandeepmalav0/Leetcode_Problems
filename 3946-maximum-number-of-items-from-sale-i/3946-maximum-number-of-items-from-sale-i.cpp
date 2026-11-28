class Solution {
public:
    int minPrice=1501;
    int solve(vector<vector<int>>& arr,vector<int>& copy,int idx,int w,vector<vector<int>>& dp){
        // base case
        if(idx<0){
            return w/minPrice;
        }

        if(dp[idx][w] != -1)return dp[idx][w];
        int take = 0;
        if(arr[idx][1] <= w){
            take = copy[idx] + 1 + solve(arr,copy,idx-1,w-arr[idx][1],dp);
        }
        int nontake = solve(arr,copy,idx-1,w,dp);
        return dp[idx][w] = max(take,nontake);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> copies(n);
        for(int i=0;i<n;i++){
            int copy=0;
            minPrice = min(minPrice,items[i][1]);
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(items[j][0]%items[i][0]==0)copy++;
            }
            copies[i]=copy;
        }

        // using DP memoization
        vector<vector<int>> dp(n,vector<int>(budget+1, -1));
        return solve(items,copies,n-1,budget,dp);
    }
};