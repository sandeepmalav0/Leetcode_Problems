class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 || vis[i][j])continue;
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j]=true;
                long long sum=grid[i][j];
                while(!q.empty()){
                    auto [r,c]=q.front();
                    q.pop();
                    for(int it=0;it<4;it++){
                        int nr = r + row[it];
                        int nc = c + col[it];
                        if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]!=0 && !vis[nr][nc]){
                            vis[nr][nc]=true;
                            sum += grid[nr][nc];
                            q.push({nr,nc});
                        }
                    }
                }
                if(sum%k == 0)ans++;
            }
        }
        return ans;
    }
};