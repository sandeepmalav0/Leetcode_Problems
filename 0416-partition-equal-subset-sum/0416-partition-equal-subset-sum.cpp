class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int val:nums)sum+=val;
        if(sum&1)return false;
        int n=nums.size();

        // using DP tabulation
        vector<vector<bool>> dp(n,vector<bool>(sum+1, 0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        dp[0][nums[0]]=1;
        for(int idx=1;idx<n;idx++){
            for(int tar=1;tar<=sum/2;tar++){
                bool nontake = dp[idx-1][tar];
                bool take = false;
                if(tar >= nums[idx]){
                    take = dp[idx-1][tar-nums[idx]];
                }
                dp[idx][tar]=(nontake||take);
            }
        }
        return dp[n-1][sum/2];
    }
};