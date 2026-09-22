class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();

        queue<vector<int>> q;
        q.push({entrance[0],entrance[1],0});
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vis[entrance[0]][entrance[1]]=true;
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            int x=u[0],y=u[1],d=u[2];
            if ((x==0 || x==m-1 || y==0 || y==n-1) && !(x==entrance[0] && y==entrance[1])){
                return d;
            }
            for(int i=0;i<4;i++){
                int nr = x+row[i];
                int nc= y+col[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && maze[nr][nc]=='.' && !vis[nr][nc]){
                    vis[nr][nc]=true;
                    q.push({nr,nc,d+1});
                }
            }
        }
        return -1;
    }
};