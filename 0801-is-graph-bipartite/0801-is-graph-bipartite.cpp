class Solution {
public:
    bool bipartite(int i, vector<vector<int>> &graph, vector<int> &color){
        if(color[i] == -1)
            color[i] = 1;
        for(auto &it : graph[i]){
            if(color[it] == -1){
                color[it] = 1 - color[i];
                if(!bipartite(it,graph,color))
                    return false;
            }
            else if(color[it] == color[i]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        for(auto &e : color) e = -1;
        for(int i = 0; i < n; i++){
            if(color[i] == -1)
                if(!bipartite(i,graph,color))
                    return false;
        }
        return true;
    }
};