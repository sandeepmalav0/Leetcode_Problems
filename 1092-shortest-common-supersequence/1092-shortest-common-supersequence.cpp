class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int m=s.length(), n=t.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int len = m+n-dp[m][n];
        int idx = len-1;
        int i=m,j=n;
        string ans(len,'$');
        while(i>0 && j>0){
            if(s[i-1]==t[j-1]){
                ans[idx]=s[i-1];
                i--;j--;
            }else if(dp[i-1][j] > dp[i][j-1]){
                ans[idx]=s[i-1];
                i--;
            }else{
                ans[idx]=t[j-1];
                j--;
            }
            idx--;
        }
        while(i>0){
            ans[idx]=s[i-1];
            idx--;i--;
        }
        while(j>0){
            ans[idx]=t[j-1];
            idx--;j--;
        }
        return ans;
    }
};