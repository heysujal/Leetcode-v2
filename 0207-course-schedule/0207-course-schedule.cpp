class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        vector<int> indegree(n);
        for(int i = 0; i < prerequisites.size(); i++){
            int first = prerequisites[i][1];
            int second = prerequisites[i][0];
            adj[first].push_back(second);
            indegree[second]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            count++;
            for(auto &it : adj[f]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }    
        }
        if(count < n)
            return false;
        return true;
    }
};