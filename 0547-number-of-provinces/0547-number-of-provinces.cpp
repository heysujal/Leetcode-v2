class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        vector<bool> vis(n,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j and isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                count++;
                vis[i] = true;
                q.push(i);
                while(!q.empty()){
                    int x = q.front();
                    q.pop();
                    for(auto it : adj[x]){
                        if(vis[it]) continue;
                        q.push(it);
                        vis[it] = true;
                    }
                }
            }
        }
        return count;
    }
};