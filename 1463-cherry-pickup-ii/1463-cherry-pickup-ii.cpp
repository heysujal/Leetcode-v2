class Solution {
public:
    int m;
    int n;
    int helper(int i, int j1, int j2, vector<vector<int>> &grid,
    vector<vector<vector<int>>> &dp){
        if(j1 < 0 or j2 < 0 or j2 >= n or j1 >= n){
            return -1e9;
        }
        if(dp[i][j1][j2] != -1){
            return dp[i][j1][j2];
        }
        if(i == m-1){
            if(j1 == j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        int ans = -1e9;
        int sum = 0;

        if(j1 == j2){
            sum += grid[i][j1];
        }
        else{
            sum += grid[i][j1] + grid[i][j2];
        }
        ans = max(ans, sum + helper(i+1, j1-1, j2-1, grid, dp));
        ans = max(ans, sum + helper(i+1, j1-1, j2, grid, dp));
        ans = max(ans, sum + helper(i+1, j1-1, j2+1, grid, dp));
        ans = max(ans, sum + helper(i+1, j1, j2-1, grid, dp));
        ans = max(ans, sum + helper(i+1, j1, j2, grid, dp));
        ans = max(ans, sum + helper(i+1, j1, j2+1, grid, dp));
        ans = max(ans, sum + helper(i+1, j1+1, j2-1, grid, dp));
        ans = max(ans, sum + helper(i+1, j1+1, j2, grid, dp));
        ans = max(ans, sum + helper(i+1, j1+1, j2+1, grid, dp));  

        return dp[i][j1][j2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return helper(0, 0, n-1, grid, dp);
    }
};