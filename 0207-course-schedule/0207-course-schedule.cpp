class Solution {
public:

    bool hasCycle(int node, vector<bool> &vis, vector<bool> &dfsvis, vector<int> *adj){
        vis[node] = true;
        dfsvis[node] = true;
        for(auto &it : adj[node]){
            if(!vis[it]){
                if(hasCycle(it, vis, dfsvis, adj)){
                    return true;
                }
            }
            else if(dfsvis[it]){
                return true;
            }
        }
        dfsvis[node] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(int i = 0; i < pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        // perform dfs and check cycle for every component
        vector<bool> vis(n, false);
        vector<bool> dfsvis(n, false);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(hasCycle(i, vis, dfsvis, adj)){
                    return false;
                }
            }
        }
        return true;
    }
};