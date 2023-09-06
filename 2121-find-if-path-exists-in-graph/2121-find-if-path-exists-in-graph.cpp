class Solution {
public:
 
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
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            vis[front] = true;
            if(front == dest)
                return true;
            for(auto it : adj[front])
                if(!vis[it])
                    q.push(it);
        }
        return false;
    }
};