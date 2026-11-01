class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        int minel = *min_element(nums.begin(),nums.end());
        for(int v:nums){
            ans += v-minel;
        }
        return ans;
    }
};