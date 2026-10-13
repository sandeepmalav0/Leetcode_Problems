class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int& v:nums){
            v = abs(v);
        }
        sort(nums.rbegin(),nums.rend());
        vector<int> big,small;
        int n=nums.size();
        int i=0,j=n-1;
        long long ans=0;
        while(i<j){
            ans += (nums[i]*nums[i]-nums[j]*nums[j]);
            i++;j--;
        }
        if(i==j){
            ans += nums[i]*nums[i];
        }
        return ans;
    }
};