class Solution {
public:
    int m = 0;
    int n = 0;
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    bool isValid(int i, int j){
        return !(i >= m or i < 0 or j < 0 or j >= n);
    }
    int getContribution(int i, int j, vector<vector<int>> &grid){
        int p = 4;
        for(auto &d : dir){
            int x = i + d[0];
            int y = j + d[1];
            if(isValid(x,y) and grid[x][y] == 1)
                p--;
        }
        return p;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    ans += getContribution(i,j,grid);
                }
            }
        }
        return ans;
    }
};