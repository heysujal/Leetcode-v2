class Solution {
private: 
    bool cycle(int node,vector<int>& vis,vector<int>& dfsvis,vector<vector<int>>& adj,vector<int>& check){
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
             if(cycle(it,vis,dfsvis,adj,check)){
                 check[node] = 0;
                 return true;
             }
            }
            else if(dfsvis[it]){
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        dfsvis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n,0);
        vector<int> dfsvis(n,0);
        vector<int> check(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cycle(i,vis,dfsvis,adj,check);
            }
        }
        for(int i = 0 ; i < n; i++)
            if(check[i] == 1)
                ans.push_back(i);
        return ans;
    }
};