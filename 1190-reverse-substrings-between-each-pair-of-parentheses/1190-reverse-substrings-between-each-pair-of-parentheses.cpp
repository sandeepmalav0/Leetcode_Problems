class Solution {
public:
    string reverseParentheses(string s) {
        string s1="";
        stack<char> st;
        for(char c:s){
            if(c==')'){
                while(st.top()!='('){
                    s1 += st.top();
                    st.pop();
                }
                st.pop();
                for(char ch:s1){
                    st.push(ch);
                }
                s1="";
            }else{
                st.push(c);
            }
        }
        string ans="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};