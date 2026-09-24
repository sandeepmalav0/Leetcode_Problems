class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for(int v:nums)s+=v;
        if(s&1)return false;

        int ans=0;
        int prefix = 0;
        for(int i=0;i<n-1;i++){
            prefix += nums[i];
            if((s-2*prefix)%2==0)ans++;
        }
        return ans;
    }
};