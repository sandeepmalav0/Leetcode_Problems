class Solution {
public:
    int n;
    int findEl(vector<int>& arr,int idx,int val){
        auto it = lower_bound(arr.begin()+idx,arr.end(),val);
        if(it!=arr.end() && *it==val){
            return it-arr.begin();
        }
        return -1;
    }
    int solve(vector<int>& arr,int idx,int inc,vector<vector<int>>& dp){
        
        if(dp[idx][inc] != -1)return dp[idx][inc];
        int len=1;
        int curVal = arr[idx]+inc;

        // First I find (curVal+1)
        int j = findEl(arr,idx+1,curVal+1);
        if(j != -1){
            len = max(len , 1 + solve(arr,j,0,dp));
        }

        // Second I find curVal exist or not then inc +1
        j = findEl(arr,idx+1,curVal);
        if(j !=-1){
            len = max(len, 1 + solve(arr,j,1,dp));
        }
        return dp[idx][inc] = len;
    }
    int maxSelectedElements(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        int len=1;
        for(int i=0;i<n;i++){
            len = max({len,solve(nums,i,0,dp),solve(nums,i,1,dp)});
        }
        return len;
        
    }
};