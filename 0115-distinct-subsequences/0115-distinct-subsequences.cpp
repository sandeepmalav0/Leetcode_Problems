class Solution {
public:
    int n,m;
    int numDistinct(string s, string t) {
        n=s.length();
        m=t.length();

        // using Space OPtimised Tabulation DP
        vector<unsigned long long> prev(m+1,0),cur(m+1,0);
        prev[0]=1;
        cur[0]=1;
        // for(int i=0;i<=n;i++){
        //     dp[i][0]=1;
        // }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    // dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                    cur[j] = prev[j-1]+prev[j];
                }else{
                    // dp[i][j] = dp[i-1][j];
                    cur[j] = prev[j];
                }
            }
            prev=cur;
        }
        // return dp[n][m];
        return prev[m];
        
    }
};