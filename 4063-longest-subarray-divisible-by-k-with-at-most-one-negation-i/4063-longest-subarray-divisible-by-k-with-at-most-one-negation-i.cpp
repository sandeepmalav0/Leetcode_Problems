class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int len=0;
        
        // using Brute force approach , T.C - O(N^2)
        for(int l=0;l<n;l++){
            int sum=0;
            unordered_set<int> mpp;
            for(int r=l;r<n;r++){
                sum += nums[r];
                int rem = ((sum%k)+k)%k;
                if(rem ==0){
                    len = max(len , r-l+1);
                }
                int newS = ((2*nums[r])%k+k)%k;
                mpp.insert(newS);
                
                if(mpp.count(rem))len=max(len,r-l+1);
            }
        }
        return len;
    }
};