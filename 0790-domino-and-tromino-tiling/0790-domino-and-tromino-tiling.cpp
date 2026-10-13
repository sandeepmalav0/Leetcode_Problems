class Solution {
public:
    int mod = 1e9+7;
    int numTilings(int n) {
        if(n<=2)return n;
        vector<long long> ans(n+1,0);
        ans[0]=1;
        ans[1]=1;
        ans[2]=2;
        for(int i=3;i<=n;i++){
            ans[i]=(2*ans[i-1]+ans[i-3])%mod;
        }
        return ans[n];
    }
};