class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        map<int,int> mpp;
        for(int v:nums)mpp[v]++;
        while(mpp.size()>0){
            auto it=mpp.begin();
            for(auto it=mpp.begin();it!=mpp.end();){
                ans.push_back(it->first);
                it->second--;
                if(it->second == 0){
                    it=mpp.erase(it);
                }else it++;
            }
        }
        return ans;
    }
};