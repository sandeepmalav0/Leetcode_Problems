class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string cur = "";
        int ans=0;
        int n= (a.length()+b.length()+1)/a.length();
        for(int i=0;i<=n;i++){
            ans++;
            cur += a;
            if(cur.find(b) != string::npos){
                return ans;
            }
        }
        return -1;
    }
};