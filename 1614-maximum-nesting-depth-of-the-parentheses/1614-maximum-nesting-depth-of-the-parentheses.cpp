class Solution {
public:
    int maxDepth(string s) {
        int ans=0,len=0;
        for(char c:s){
            if(c=='('){
                len++;
                ans = max(len,ans);
            }else if(c==')'){
                len--;
            }
        }
        return ans; 
    }
};