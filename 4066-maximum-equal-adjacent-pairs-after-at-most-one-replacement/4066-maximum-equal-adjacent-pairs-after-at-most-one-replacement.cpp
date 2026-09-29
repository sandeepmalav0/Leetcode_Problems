class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int cnt=0;
        map<pair<int,int>,int> mp;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1])ans++;
            else{
                int a=min(nums[i],nums[i+1]);
                int b=max(nums[i],nums[i+1]);
                mp[{a,b}]++;
                cnt=max(cnt,mp[{a,b}]);
            }
        }
        return ans+cnt;
    }
};