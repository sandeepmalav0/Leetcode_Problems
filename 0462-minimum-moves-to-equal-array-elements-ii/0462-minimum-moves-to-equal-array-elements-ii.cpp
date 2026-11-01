class Solution {
public:
    int minMoves2(vector<int>& nums){
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        int ans = 0;
        for (int v : nums) {
            ans += abs(v - median);
        }
        return ans;

        /* approach which i used , but wrong
        int n=nums.size();
        int sum=0;
        for(int v:nums)sum+=v;
        int q1=sum/n;
        int q2=q1+1;
        int ans1=0,ans2=0;
        for(int v:nums){
            ans1 += abs(v-q1);
            ans2 += abs(v-q2);
        }
        return min(ans1,ans2);*/
    }
};