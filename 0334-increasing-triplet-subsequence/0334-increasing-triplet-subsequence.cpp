class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int first=INT_MAX,second=INT_MAX;
        for(int v:nums){
            if(v <= first){
                first = v;
            }else if(v <= second){
                second = v;
            }else return true;
        }
        return false;
    }
};