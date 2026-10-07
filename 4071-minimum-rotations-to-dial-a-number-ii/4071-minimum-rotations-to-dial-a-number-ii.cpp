class Solution {
public:
    int dist(char a,char b){
        int d1 = abs(a-b);
        return min(d1,10-d1);
    }
    int minRotations(int n, string s) {
        vector<int> preSum(n);
        preSum[0] = dist(s[0],'0');
        for(int i=1;i<n;i++){
            preSum[i] = preSum[i-1] + dist(s[i],s[i-1]);
        }
        int ans = preSum[n-1];
        int dis = 0;
        for(int i=n-2;i>=0;i--){
            dis += dist(s[i],s[i+1]);
            if(i==0){
                int cost = dist('0',s[n-1])+dis;
                ans = min(ans,cost);
            }else{
                int cost = preSum[i-1]+dis+dist(s[i-1],s[n-1]);
                ans = min(ans,cost);
            }
        }
        return ans;
    }
};