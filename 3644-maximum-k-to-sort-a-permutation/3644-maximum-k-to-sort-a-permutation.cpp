class Solution {
public:
    int n;
    bool isSort(vector<int>& arr){
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1])return false;
        }return true;
    }
    int sortPermutation(vector<int>& nums) {
        n=nums.size();
        if(n==1 || isSort(nums))return 0;
        if(nums[0] != 0)return 0;
        int k=0,el=0;
        bool first=true;
        for(int v:nums){
            if(v != el){
                if(first){
                    first=false;
                    k=v;
                }else{
                    k &= v;
                }
            }
            el++;
        }
        return k;
    }
};