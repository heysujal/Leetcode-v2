class Solution {
public:
    int m;
    int n;
    int helperTab(vector<vector<int>> &grid){
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // filling up base case i.e last row and last column
        vector<int> next(n, 0);
        next[n-1] = grid[m-1][n-1];
        for(int col = n-2; col >= 0; col--){
            next[col] = grid[m-1][col] + next[col+1];
        }
        for(int i = m-2; i >= 0; i--){
            vector<int> curr(n, 1e9);
            curr[n-1] = grid[i][n-1] + next[n-1];
            for(int j = n-2; j >= 0; j--){
                curr[j] = grid[i][j] + min(curr[j+1], next[j]);
            }
            next = curr;
        }
        return next[0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        return helperTab(grid);
    }
};