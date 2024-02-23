class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n, INT_MAX);
        vector<pair<int, int>> adj[n];

        for(auto &v : flights){
            adj[v[0]].push_back({v[1], v[2]});
        }
        // node, distance
        queue<pair<int, int>> q;
        q.push({src, 0});
        distance[src] = 0;
        int steps = 0;
        while(!q.empty() and steps <= k){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int u = q.front().first;
                int d = q.front().second;
                q.pop();
                for(auto &it : adj[u]){
                    int v = it.first;
                    int cost = it.second;
                    if(distance[v] > d + cost){
                        distance[v] = d + cost;
                        q.push({v, d + cost});
                    }
                }
            }
            steps++;
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};