class Solution {
public:
int n;
    int f(vector<int>& nums, int idx, int prev,vector<vector<int>>& dp) {
        if (idx == n)return 0;

        if (dp[idx][prev + 1] != -1)return dp[idx][prev + 1];

        int choose = 0;
        if (prev == -1 || nums[idx] > nums[prev]) {
            choose = 1 + f(nums, idx + 1, idx, dp);
        }
        int nochoose = f(nums, idx + 1, prev, dp);
        return dp[idx][prev + 1] = max(choose, nochoose);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n + 1, -1));
        return f(nums, 0, -1, dp);
    }
};