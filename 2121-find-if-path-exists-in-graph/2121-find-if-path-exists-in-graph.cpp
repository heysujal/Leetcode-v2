class Solution {
public:
    bool flag = false;
    void dfs(int i, vector<bool> &vis, vector<int> *adj, int dest){
        if(i==dest){
            flag = true;
            return;
        }
        if(vis[i]) return;
        vis[i] = true;
        for(auto it : adj[i])
            dfs(it,vis,adj,dest);
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {
        // make a adjacency list
        vector<int> adj[n];
        vector<bool> vis(n, false);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(source, vis, adj, dest);
        return flag;
    }
};