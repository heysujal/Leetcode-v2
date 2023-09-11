class Solution {
public:
    void dfs(int i, vector<bool> &vis, vector<int> *adj){
        vis[i] = true;
        for(auto it : adj[i]){
            if(!vis[it])
                dfs(it,vis,adj);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int count = 0;
        if(connections.size() < n-1)
            return -1;  //minimum n-1 edges are required to keep the graph connected
        vector<bool> vis(n);
        vector<int> adj[n];
        for(auto &v : connections){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                count++;
            }
        }
        return count-1;
    }
};