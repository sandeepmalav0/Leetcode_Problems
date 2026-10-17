class Solution {
public:
    int digSum(int num){
        int sum=0;
        while(num>0){
            sum += num%10;
            num/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr=nums;
        unordered_map<int,int> Index;
        for(int i=0;i<n;i++){
            Index[nums[i]]=i;
        }
        
        auto comp = [&](int a, int b) {
            int diga = digSum(a);
            int digb = digSum(b);
            if (diga == digb) {
                return a < b;
            }
            return diga < digb;
        };
        sort(arr.begin(),arr.end(),comp);

        int noOfswaps=0;
        for(int i=0;i<n;i++){
            if(arr[i]==nums[i])continue;

            int expIdx = Index[arr[i]];
            swap(nums[i],nums[expIdx]);
            
            Index[nums[i]]=i;
            Index[nums[expIdx]]=expIdx;
            noOfswaps++;
        }
        return noOfswaps;
    }
};