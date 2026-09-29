class Solution {
public:
    int m,n,total;
    bool isValidCheck(int r,int c,int open,vector<vector<char>>& arr,vector<vector<vector<int>>>& dp){
        if(r>=m || c>=n)return false;
        
        if(arr[r][c]=='('){open++;}
        else{open--;}
        
        if(open<0)return false;
        if(open > total/2)return false;
        if(r==m-1 && c==n-1){
            return open==0;
        }
        
        if(dp[r][c][open] != -1)return dp[r][c][open];
        
        bool right = isValidCheck(r,c+1,open,arr,dp);
        bool bottom = isValidCheck(r+1,c,open,arr,dp);
        return dp[r][c][open]=(right || bottom);
    }
    bool hasValidPath(vector<vector<char>>& grid){
        m=grid.size(),n=grid[0].size();
        if(grid[0][0]==')')return false;
        if(grid[m-1][n-1]=='(')return false;
        total=m+n-1;
        if(total&1)return false;

        // using DP memoization
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(total+1,-1)));
        return isValidCheck(0,0,0,grid,dp);
    }
};