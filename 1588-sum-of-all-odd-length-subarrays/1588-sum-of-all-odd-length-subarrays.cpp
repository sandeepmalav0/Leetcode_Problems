class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        // brute force approach using T.C - O(N^2)
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += arr[j];
                if((j-i+1)%2 == 1){
                    ans += sum;
                }
            }
        }
        return ans;
    }
};