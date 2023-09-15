class Solution {
public:
    bool bipartite(int node, int col, vector<int> &color, vector<vector<int>>& adj){
        color[node] = col;
        for(auto it : adj[node]){
            if(color[it] == -1){
                if(!bipartite(it, !col, color, adj))
                    return false;
            }
            else if(color[it] == color[node])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1)
                if(!bipartite(i, 0, color, adj))    
                    return false;
        }
        return true;
    }
};