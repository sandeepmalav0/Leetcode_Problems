class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int cnt=0;
        vector<int> ans(seq.size());
        for(int i=0;i<seq.size();i++){
            if(seq[i]=='('){
                cnt++;
                ans[i]= (cnt%2==0);
            }else if(seq[i]==')'){
                ans[i] = (cnt%2==0);
                cnt--;
            }
        }
        return ans;
    }
};