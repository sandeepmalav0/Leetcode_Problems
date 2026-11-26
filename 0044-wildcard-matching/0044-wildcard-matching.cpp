class Solution {
public:
    int m,n;
    bool isMatch(string s, string p){
        m=s.length();
        n=p.length();

        // Tabulation DP approach
        vector<vector<bool>> dp(m+1,vector<bool>(n+1, false));
        dp[0][0]=true;
        for(int j=1;j<=n;j++){
            bool flag=true;
            for(int k=0;k<j;k++){
                if(p[k] != '*'){
                    flag=false;
                    break;
                }
            }
            dp[0][j]=flag;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j] = dp[i-1][j]||dp[i][j-1];
                }else{
                    dp[i][j]=false;
                }
            }
        }
        return dp[m][n];
    }
};