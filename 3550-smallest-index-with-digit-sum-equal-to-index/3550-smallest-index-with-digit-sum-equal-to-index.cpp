class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int s=0,val=nums[i];
            while(val>0){
                s += val%10;
                val/=10;
            }
            if(s==i)return i;
        }
        return -1;
        
    }
};