class Solution {
public:
    int isDig(int x,int y){
        int sum=x+y;
        return sum%10;
    }
    int triangularSum(vector<int>& nums) {
        while(nums.size()>1){
            vector<int> arr;
            int n=nums.size();
            for(int i=0;i<n-1;i++){
                arr.push_back(isDig(nums[i],nums[i+1]));
            }
            nums=arr;
        }
        return nums[0];
    }
};