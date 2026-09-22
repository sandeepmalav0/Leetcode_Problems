class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(int v:stones)sum+=v;
        int n = stones.size();
        // using DP Tabulation - Partition a set into two subsets with minimum absolute sum difference
        vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        dp[0][stones[0]]=1;
        for(int idx=1;idx<n;idx++){
            for(int tar=1;tar<=sum;tar++){
                bool noake = dp[idx-1][tar];
                bool take=false;
                if(tar >= stones[idx]){
                    take = dp[idx-1][tar-stones[idx]];
                }
                dp[idx][tar]=(noake||take);
            }
        }
        int weightRemainStone=sum+1;
        for(int dif=0;dif<=sum/2;dif++){
            if(dp[n-1][dif]){
                weightRemainStone = min(weightRemainStone, sum-2*dif);
            }
        }
        return weightRemainStone;
    }
};