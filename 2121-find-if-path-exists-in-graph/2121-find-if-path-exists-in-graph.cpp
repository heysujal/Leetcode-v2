class Solution {
public:
    vector<int> parent; // mapping for node to parent
    vector<int> rank;
    int findParent(int node){
        if(parent[node] == node)
            return node;
        return findParent(parent[node]); 
    }
    void makeParent(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }
        else{
            parent[pu] = pv; // pick anyone as parent
            rank[pv]++;
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        for(auto e : edges){
            makeParent(e[0], e[1]);
        }
        return findParent(source) == findParent(destination);
    }
};