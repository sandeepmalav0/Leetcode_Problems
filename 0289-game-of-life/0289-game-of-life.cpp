class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // using Brute force , Extra space O(n^2)
        int m=board.size(), n=board[0].size();
        vector<vector<int>> ans=board;
        int row[]={-1,-1,0,1,1,1,0,-1};
        int col[]={0,1,1,1,0,-1,-1,-1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int live = 0;
                for(int k=0;k<8;k++){
                    int nr = i+row[k];
                    int nc = j+col[k];
                    if(nr>=0 && nc>=0 && nr<m && nc<n){
                        if(board[nr][nc]==1)live++;
                    }
                }
                if(live<2){
                    ans[i][j]=0;
                }else if(live>3){
                    ans[i][j]=0;
                }else if(live==3){
                    ans[i][j]=1;
                }
            }
        }
        board=ans;
    }
};