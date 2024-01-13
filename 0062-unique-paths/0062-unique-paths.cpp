class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if (i == m - 1 and j == n - 1)
            return 1;
        if (i >= m or j >= n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = solve(i + 1, j, m, n, dp) + solve(i, j + 1, m, n, dp);
    }
    int solveTab(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // dp[i][j] means number of paths from i,j to m-1, n-1
        // if row is m-1 then dp[m-1] = 1 for all j
        // which means only way to go is in Right direction
        for(int j = 0; j < n; j++)
            dp[m-1][j] = 1;
        for(int i = m-2; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                dp[i][j] += dp[i+1][j];
                if(j != n-1)
                    dp[i][j] += dp[i][j+1];
            }
        }
        return dp[0][0];
    }
    int uniquePaths(int m, int n) { 
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(0, 0, m, n, dp); 
        return solveTab(m, n);
    }
};