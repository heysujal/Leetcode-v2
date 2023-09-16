class Solution {
private:
   bool dfsCheck(int node,vector<int>& vis,vector<int>& pathVis,vector<int> adj[],stack<int>& st){
    vis[node]=1;
    pathVis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfsCheck(it,vis,pathVis,adj,st))
                 return true;
        }
        else if(pathVis[it]) return true;
    }
    st.push(node);
    pathVis[node]=0;
    return false;
}
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<int> adj[n];

        stack<int> st;
        vector<int> ans;
        for(int i=0;i<prerequisites.size();i++){
           int first = prerequisites[i][0];
           int second = prerequisites[i][1];
           adj[second].push_back(first);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfsCheck(i,vis,pathVis,adj,st)) return {};
            }
        }
       
        while(st.size()!=0){
             cout<<st.top();
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};