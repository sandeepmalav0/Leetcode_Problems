class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int n=s.length();

        // Space Optimized DP tabulation approach , T.C - O(n*n) , S.C - O(2*n)
        vector<int> prev(n+1,0),cur(n+1,0);
        // base case dp[i][0]=0 , dp[0][j]=0 , include already.
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s2[j-1]){
                    cur[j] = 1 + prev[j-1];
                }else{
                    cur[j] = max(prev[j] , cur[j-1]);
                }
            }
            prev=cur;
        }
        return prev[n];
    }
};