class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int flag = 0;

        for(char c:s){
            if(c=='('){
                if(flag==0){
                    flag++;
                    continue;
                }
                flag++;
                ans += c;
            }else{
                flag--;
                if(flag==0){
                    continue;
                }
                ans += c;
            }
        }
        return ans;
    }
};