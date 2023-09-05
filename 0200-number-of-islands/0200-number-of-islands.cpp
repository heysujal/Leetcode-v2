class Solution {
public:
    int m;
    int n;
    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid){
        if(i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == '0' or vis[i][j])
            return;
        vis[i][j] = true; // no need of backtrack logic bcoz we using vis for that
        dfs(i+1, j, vis, grid);
        dfs(i-1, j, vis, grid);
        dfs(i, j+1, vis, grid);
        dfs(i, j-1, vis, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] and grid[i][j] == '1'){
                    count++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return count;
    }
};