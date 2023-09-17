class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> topo;
        vector<int> adj[n];
        vector<int> indegree(n);
        for(int i=0;i<prerequisites.size();i++){
           int first = prerequisites[i][0];
           int second = prerequisites[i][1];
           adj[second].push_back(first);
           indegree[first]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto &it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        if(topo.size() < n)
            return {};
        return topo;
    }
};