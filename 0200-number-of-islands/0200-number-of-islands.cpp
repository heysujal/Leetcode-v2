class Solution {
public:
    int m;
    int n;
    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid){
        vis[i][j] = true;

        if(i-1 >= 0 and i-1 < m and j >=0 and j < n and grid[i-1][j] == '1' and !vis[i-1][j]){
            dfs(i-1,j,vis,grid);
        }
        if(i+1 >= 0 and i+1 < m and j >=0 and j < n and grid[i+1][j] == '1' and !vis[i+1][j]){
            dfs(i+1,j,vis,grid);
        }
        if(i >= 0 and i < m and j-1 >=0 and j-1 < n and grid[i][j-1] == '1' and !vis[i][j-1]){
            dfs(i,j-1,vis,grid);
        }
        if(i >= 0 and i < m and j+1 >=0 and j+1 < n and grid[i][j+1] == '1' and !vis[i][j+1]){
            dfs(i,j+1,vis,grid);
        }
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