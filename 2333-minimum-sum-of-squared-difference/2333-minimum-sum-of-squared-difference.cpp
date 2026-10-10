class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        long long k = 1LL*k1+k2;
        vector<int> arr;
        long long total = 0;
        for(int i=0;i<n;i++){
            int diff = abs(nums1[i]-nums2[i]);
            arr.push_back(diff);
            total += diff;
        }
        if(k >= total)return 0;
        sort(arr.rbegin(),arr.rend());
        arr.push_back(0);
        long long ans=0;
        int idx = 0;
        for(int i=0;i<n;i++){
            int len=i+1;
            long long req = (1LL*(arr[i]-arr[i+1]))*len;
            if(k >= req){
                k -= req;
            }else{
                long long allred = k/len;
                long long somered = k%len;

                int v1 = arr[i]-allred-1;
                int v2 = arr[i]-allred;

                ans += somered*v1*v1;
                ans += (len-somered)*v2*v2;
                idx=i+1;
                break;
            }
        }
        for(int i=idx;i<n;i++){
            ans += 1LL*arr[i]*arr[i];
        }
        return ans;
    }
};