class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev(1,1);
        for(int i=1;i<=rowIndex;i++){
            vector<int> cur(i+1,1);
            for(int j=1;j<i;j++){
                cur[j]=prev[j-1]+prev[j];
            }
            prev=cur;
        }
        return prev;
    }
};