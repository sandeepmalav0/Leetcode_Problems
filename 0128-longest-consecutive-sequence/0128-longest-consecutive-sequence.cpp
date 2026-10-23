class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        
        // Optimal Approach using Hashing (set) , T.C - O(n)
        unordered_set<int> st(begin(nums),end(nums));
        int ans=1;
        for(auto v:st){
            if(st.find(v-1)==st.end()){
                int num=v, cnt=0;
                while(st.find(num)!=st.end()){
                    cnt++;
                    num++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;


        // using Sort , T.C - O(nlogn)
        /*sort(begin(nums),end(nums));
        int ans=1,c=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]+1 == nums[i+1]){
                c++;
                ans = max(ans,c);
            }else if(nums[i]==nums[i+1]){
                continue;
            }else c=1;
        }
        return ans;*/
    }
};