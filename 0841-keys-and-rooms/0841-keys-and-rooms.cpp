class Solution {
public:
    void dfs(int cur,vector<vector<int>>& rooms,vector<int>& vis){
        vis[cur]=true;
        for(int v:rooms[cur]){
            if(!vis[v]){
                dfs(v,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        if(rooms[0].size()==0)return false;
        vector<int> vis(n,false);
        
        // using graph DFS Traversal
        dfs(0,rooms,vis);
        for(int i=0;i<n;i++){
            if(!vis[i])return false;
        }
        return true;

        // using graph BFS Traversal
        /*vis[0]=true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int r=q.front();
            q.pop();
            for(int k:rooms[r]){
                if(!vis[k]){
                    vis[k]=true;
                    q.push(k);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i])return false;
        }
        return true;*/
    }
};