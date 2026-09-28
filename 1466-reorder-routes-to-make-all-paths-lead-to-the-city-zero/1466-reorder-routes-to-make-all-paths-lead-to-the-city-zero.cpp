class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> out(n);
        vector<vector<int>> in(n);
        for(auto v:connections){
            out[v[0]].push_back(v[1]);
            in[v[1]].push_back(v[0]);
        }
        queue<int> q;
        q.push(0);
        vector<bool> vis(n,false);
        vis[0]=true;
        int ans=0;
        while(!q.empty()){
            int node=q.front();q.pop();
            for(int v:in[node]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            } 
            for(int v:out[node]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                    ans++;
                }
            }
        }
        return ans;
    }
};