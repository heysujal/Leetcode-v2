class Solution {
public:
    // nummber of components
    void dfs(int i, vector<vector<int>> &grid, vector<bool> &vis){
        vis[i] = true;
        for(int j = 0; j < grid.size(); j++){
            if(grid[i][j]==1 and !vis[j])
                dfs(j, grid, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        vector<bool> vis(m,false);
        for(int i = 0; i < m; i++){
            if(!vis[i]){
                dfs(i, grid, vis);
                count++;
            }
        }
        return count;
    }
};