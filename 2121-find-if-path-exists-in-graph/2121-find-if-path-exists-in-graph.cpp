class Solution {
public:
    bool dfs(int i, vector<bool> &vis, vector<int> *adj, int dest){
        if(i==dest)
            return true;
        if(vis[i]) return false;
        vis[i] = true;
        for(auto it : adj[i])
            if(dfs(it,vis,adj,dest))
                return true;
        return false;
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
        return dfs(source, vis, adj, dest);
    }
};