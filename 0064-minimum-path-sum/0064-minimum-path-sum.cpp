class Solution {
public:
    int m;
    int n;
    int helperTab(vector<vector<int>> &grid){
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // filling up base case i.e last row and last column
        dp[m-1][n-1] = grid[m-1][n-1];
        for(int col = n-2; col >= 0; col--){
            dp[m-1][col] = grid[m-1][col] + dp[m-1][col+1];
        }
        for(int row = m-2; row >= 0; row--){
            dp[row][n-1] = grid[row][n-1] + dp[row+1][n-1];
        }
        for(int i = m-2; i >= 0; i--){
            for(int j = n-2; j >= 0; j--){
                dp[i][j] = grid[i][j] + min(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        return helperTab(grid);
    }
};