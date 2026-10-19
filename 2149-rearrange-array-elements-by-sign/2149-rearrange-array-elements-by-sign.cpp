class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> pos,neg;
        for(int v:nums){
            if(v>0){
                pos.push_back(v);
            }else{
                neg.push_back(v);
            }
        }
        vector<int> ans;
        int idx=0;
        for(int i=0;i<n;i+=2){
            nums[i]=pos[idx];
            nums[i+1]=neg[idx];
            idx++;
        }
        return nums;
    }
};