class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mpp;
        for(auto v:knowledge){
            mpp[v[0]]=v[1];
        }
        int n=s.length();
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                string txt="";
                i++;
                while(s[i]!=')'){
                    txt += s[i];
                    i++;
                }
                if(mpp.find(txt)!=mpp.end()){
                    ans += mpp[txt];
                }else{
                    ans += '?';
                }
            }
            if(s[i]==')')continue;
            ans += s[i];
        }
        return ans;
    }
};