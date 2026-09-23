class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size() ; 
        int sum=0;
        for(int v:nums)sum+=v;
        if(x > sum)return -1;
        int tar = sum-x;
        int l=0;
        int len = -1;
        int s=0;
        for(int r=0;r<n;r++){
            s += nums[r];
            while(s > tar){
                s -= nums[l];
                l++;
            }
            if(s == tar){
                len = max(len,r-l+1);
            }
        }
        if(len == -1) return -1;
        return n-len;
    }
};