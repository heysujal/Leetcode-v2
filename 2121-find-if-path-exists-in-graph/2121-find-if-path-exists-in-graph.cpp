class Solution {
public:
    bool flag = false;
    void dfs(int i, int dest, vector<bool> &vis, vector<int> *adj){
        if(i == dest){
            flag = true;
            return;
        }
        vis[i] = true;
        for(auto &it  : adj[i])
            if(!vis[it])
                dfs(it,dest,vis,adj);
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // make a adjacency list
        vector<int> adj[n];
        vector<bool> vis(n, false);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(source, destination, vis, adj);
        return flag;
    }
};