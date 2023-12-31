class Solution {
public:
    int m = 0;
    int n = 0;
    void isSurrounded(int i, int j, vector<vector<char>> &grid){
        if(i < 0 or j < 0 or i >= m or j >= n or grid[i][j] != 'O')
            return;
        grid[i][j] = '#'; // mark as visted to avoid infinite Recursion
        isSurrounded(i,j-1,grid);
        isSurrounded(i,j+1,grid);
        isSurrounded(i+1,j,grid);
        isSurrounded(i-1,j,grid);
    }
    void solve(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 or j == 0 or i == m-1 or j == n-1){
                    isSurrounded(i,j,grid);
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'O'){
                    grid[i][j] = 'X';
                }
                if(grid[i][j] == '#'){
                    grid[i][j] = 'O';
                }
            }
        }
    }
};