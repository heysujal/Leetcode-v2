class Solution {
public:
    bool cycle(int node, vector<bool> &vis, vector<bool> &dfsvis, vector<int> *adj){
        vis[node] = true;
        dfsvis[node] = true;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(cycle(it,vis,dfsvis,adj))
                    return true;
            }
            else if(dfsvis[it]){
                return true;
            }
        }
        dfsvis[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i = 0; i < prerequisites.size(); i++){
            int first = prerequisites[i][1];
            int second = prerequisites[i][0];
            adj[first].push_back(second);
        }
        vector<bool> vis(numCourses, false);
        vector<bool> dfsvis(numCourses, false);
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(cycle(i,vis,dfsvis,adj))
                    return false;
            }
        }
        return true;
    }
};