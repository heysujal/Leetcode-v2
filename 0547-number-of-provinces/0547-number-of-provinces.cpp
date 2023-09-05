class Solution {
public:
    void dfs(int i, vector<bool> &vis, vector<int> *adj){
        if(vis[i]) return;
        vis[i] = 1;
        for(auto n : adj[i]){
            if(!vis[n])
                dfs(n,vis,adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int V = isConnected.size();
        vector<bool> vis(V+1);
        vector<int> adj[V+1];
        // adj list done
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(i!=j and isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        for(int i = 1; i <= V; i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,adj);
            }
        }
        return count;
    }
};