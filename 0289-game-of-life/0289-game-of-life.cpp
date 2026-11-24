class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // using In-place , S.C - O(1), T.C - O(m*n)

        int m=board.size(), n=board[0].size();        
        int row[]={-1,-1,0,1,1,1,0,-1};
        int col[]={0,1,1,1,0,-1,-1,-1};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int live = 0;
                for(int k=0;k<8;k++){
                    int nr = i+row[k];
                    int nc = j+col[k];
                    if(nr>=0 && nc>=0 && nr<m && nc<n){
                        if(board[nr][nc]==1 || board[nr][nc]==3)live++;
                    }
                }
                if(board[i][j]==0 && live==3){
                    board[i][j]=2;
                }else if(board[i][j]==1){
                    if(live<2 || live>3){
                        board[i][j]=3;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==2){
                    board[i][j]=1;
                }else if(board[i][j]==3){
                    board[i][j]=0;
                }
            }
        }
    }
};