class Solution {
public:
    int m,n;
    int solve(string& s,string& t,int i,int j,vector<vector<int>>& dp){
        // Base case
        if(i==0)return j;
        if(j==0)return i;

        if(dp[i][j] != -1)return dp[i][j];
        if(s[i-1]==t[j-1]){
            return dp[i][j] = 0 + solve(s,t,i-1,j-1,dp);
        }
        return dp[i][j] = 1 + min({solve(s,t,i,j-1,dp), solve(s,t,i-1,j,dp), solve(s,t,i-1,j-1,dp)});
    }
    int minDistance(string s, string t){
        m=s.length();
        n=t.length();

        // using memoization and 1 indexed DP approach
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(s,t,m,n,dp);
    }
};