class Solution {
public:
    int m = 0;
    int n = 0;
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    bool isValid(int i, int j){
        return !(i >= m or i < 0 or j < 0 or j >= n);
    }
    int contributionCal(int i, int j, vector<vector<int>> &grid){
        int p = 4;
        for(auto &d : dir){
            int x = i + d[0];
            int y = j + d[1];
            if(isValid(x,y) and grid[x][y] == 1)
                p--;
        }
        return p;
    }
    void dfs(int i, int j, int &perimeter, vector<vector<bool>> &vis,vector<vector<int>> &grid){
        if(!isValid(i,j) or grid[i][j] == 0 or vis[i][j])
            return;
        vis[i][j] = true;
        int contribution = contributionCal(i,j,grid);
        perimeter += contribution;
        for(auto &d : dir){
            int x = i + d[0];
            int y = j + d[1];
            if(isValid(x,y) and grid[x][y] == 1 and !vis[x][y])
                dfs(x,y,perimeter,vis,grid);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int perimeter = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 and !vis[i][j]){
                    dfs(i,j,perimeter,vis,grid);
                    return perimeter;
                }
            }
        }
        return 0;
    }
};