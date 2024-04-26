class Solution {
public:

    int helper(int i, int skipColumn, vector<vector<int>> &grid,
        vector<vector<int>> &dp){
        if(i == grid.size()){
            return 0;
        }

        if(dp[i][skipColumn + 1] != -1){
            return dp[i][skipColumn + 1];
        }
        int ans = INT_MAX;
        for(int col = 0; col < grid.size(); col++){
            if(col == skipColumn){
                continue;
            }
            ans = min(ans, grid[i][col] + helper(i+1, col, grid, dp));
        }
        return dp[i][skipColumn + 1] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans = helper(0, -1, grid, dp);
        return ans;
    }
};