class Solution {
public:
int m,n;
    void helper(int r,int c,vector<vector<int>>& arr){
        for(int i=0;i<m;i++){
            arr[i][c]=0;
        }
        for(int j=0;j<n;j++){
            arr[r][j]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        vector<pair<int,int>> zeros;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    zeros.push_back({i,j});
                }
            }
        }
        for(auto [i,j]:zeros){
            helper(i,j,matrix);
        }
    }
};