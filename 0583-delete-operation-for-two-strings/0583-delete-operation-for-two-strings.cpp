class Solution {
public:
    int minDistance(string s1, string s2){
        int m = s1.length(), n=s2.length();

        // using space optimised DP , longest common subsequence.
        vector<int> pre(n+1,0),cur(n+1,0);
        // pre[i]=0 and cur[j]=0 , already base case included
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    cur[j]=1+pre[j-1];
                }else{
                    cur[j]=max(pre[j],cur[j-1]);
                }
            }
            pre=cur;
        }
        return m+n-2*pre[n];
    }
};