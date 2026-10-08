class Solution {
public:
    
    int helper(vector<int>& arr,int idx,int tar,vector<vector<int>>& dp){
        if(tar<0)return 0;
        if(tar==0)return 1;
        if(idx== -1){
            return tar==0;
        }
        if(dp[idx][tar] != -1)return dp[idx][tar];
        int notake = helper(arr,idx-1,tar,dp);
        int take = helper(arr,idx,tar-arr[idx],dp);
        
        return dp[idx][tar]=notake+take;
    }
    vector<int> findCoins(vector<int>& numWays) {
        int n=numWays.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1 , -1));
        vector<int> ans;
        for(int i=0;i<n;i++){
            int tar = i+1;
            int ways = helper(ans,ans.size()-1,tar,dp);
            if(ways == numWays[i]-1)ans.push_back(tar);
            else if(ways != numWays[i])return {};
        }
        return ans;
    }
};