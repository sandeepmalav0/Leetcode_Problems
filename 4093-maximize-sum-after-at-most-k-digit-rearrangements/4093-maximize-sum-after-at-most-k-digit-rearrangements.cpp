class Solution {
public:
    int is(int x){
        string s=to_string(x);
        sort(s.rbegin(),s.rend());
        int newx = stoi(s);
        return newx-x;

    }
    long long maximizeSum(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        vector<int> dif;
        for(int v:nums){
            sum += v;
            dif.push_back(is(v));
        } 
        sort(dif.rbegin(),dif.rend());
        for(int i=0;i<k;i++){
            sum += dif[i];
        }
        return sum;
    }
};