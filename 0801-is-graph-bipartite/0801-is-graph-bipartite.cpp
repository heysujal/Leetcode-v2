class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(color[i] == 0){ // non-visited
                q.push(i);
                color[i] = 1;
                while(!q.empty()){
                    auto f = q.front(); q.pop();
                    for(auto &it : graph[f]){
                        if(color[it] == 0){ // unvisited
                            color[it] = -color[f];
                            q.push(it);
                        }
                        // if neighbour has same color then -> Not bipartite
                        else if(color[it] == color[f]){ 
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};