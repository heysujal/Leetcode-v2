class Solution {
public: 
    int m = 0;
    int n = 0;
    void canGoOff(int i, int j, vector<vector<int>>& grid){
        if(i < 0 or j < 0 or i >= m or j >=n or grid[i][j] == 0)
            return;
        grid[i][j] = 0; // mark as visited
        canGoOff(i-1,j,grid);
        canGoOff(i+1,j,grid);
        canGoOff(i,j+1,grid);
        canGoOff(i,j-1,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        for(int i = 0; i < m ; i++){
            for(int j = 0 ; j < n; j++){
                if(i == 0 or i == m-1 or j == 0 or j == n-1) // boundary cell
                    if(grid[i][j] == 1)
                        canGoOff(i,j,grid);
            }
        }
        for(int i = 0; i < m ; i++){
            for(int j = 0 ; j < n; j++){
                    if(grid[i][j] == 1)
                        count++;
            }
        }
        return count;
    }
};