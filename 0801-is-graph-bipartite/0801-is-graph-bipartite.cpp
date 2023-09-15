class Solution {
public:
    bool bipartiteBFS(int node, int col, vector<int> &color, vector<vector<int>> &adj){
        queue<int> q;
        q.push(node);
        color[node] = col;
        while(!q.empty()){
            auto f = q.front(); q.pop();
            for(auto it : adj[f]){
                if(color[it] == -1){
                    color[it] = !color[f];
                    q.push(it);
                }
                else if(color[it] == color[f]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> q;
        int col = 0;
        for(int i = 0; i < n; i++){
            if(color[i] == -1){ // non-visited
                if(!bipartiteBFS(i,col,color,graph))
                    return false;
            }
        }
        return true;
    }
};