class Solution {
public:
    int m;
    int n;
    bool res = true;
    void dfs(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2){
        if(i < 0 or j < 0 or i >= m or j >= n or grid2[i][j] != 1)
            return;
        if(grid1[i][j] != 1){ // No land in grid1 
            res = false;
            return;
        }
        grid2[i][j] = 0; // mark as visited
        dfs(i-1,j,grid1,grid2);
        dfs(i+1,j,grid1,grid2);
        dfs(i,j+1,grid1,grid2);
        dfs(i,j-1,grid1,grid2);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid2[i][j] == 1){
                    res = true;
                    dfs(i,j,grid1,grid2);
                    if(res)
                        count++;
                }
            }
        }
        return count;
    }
};