class Solution {
public:
    const int mod = 1e9 + 7;
    int helper(int i, int j, int k, int m, int n, vector<vector<vector<int>>> &dp){
        if(k < 0){
            return 0;
        }
        if(i < 0 or i >= m or j < 0 or j >= n){
            return 1;
        }
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        int op = 0;
        op = (op%mod + helper(i+1, j, k-1, m, n, dp)%mod)%mod;
        op = (op%mod + helper(i, j+1, k-1, m, n, dp)%mod)%mod;
        op = (op%mod + helper(i-1, j, k-1, m, n, dp)%mod)%mod;
        op = (op%mod + helper(i, j-1, k-1, m, n, dp)%mod)%mod;
        return dp[i][j][k] = op%mod;
    }

    int findPaths(int m, int n, int k, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int>(k+1, -1)));
        return helper(startRow, startColumn, k, m, n, dp);
    }
};