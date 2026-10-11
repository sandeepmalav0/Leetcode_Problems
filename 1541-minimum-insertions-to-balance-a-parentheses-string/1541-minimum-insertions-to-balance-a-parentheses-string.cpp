class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        int i=0;
        int res = 0;
        int cnt = 0;
        while(i<n){
            char c= s[i];
            if(c=='('){
                cnt++;
                i++;
            }else{
                if(cnt > 0){
                    cnt--;
                }else{
                    res++;
                }
                if(i<n-1 && s[i+1]==')'){
                    i+=2;
                }else{
                    res++;
                    i++;
                }
            }
        }
        return res+2*cnt;
    }
};