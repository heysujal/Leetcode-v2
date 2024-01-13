class Solution {
public:

    int solveTab(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n, 0));
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
    int solveSpace(int m, int n){
        vector<int> prev(n, 0);
        for(int j = 0; j < n; j++)
            prev[j] = 1;
        for(int i = m-2; i >= 0; i--){
            vector<int> curr(n, 0);
            for(int j = n-1; j >= 0; j--){
                curr[j] += prev[j];
                if(j != n-1)
                    curr[j] += curr[j+1];
            }
            prev = curr;
        }
        return prev[0];
    }
    int uniquePaths(int m, int n) { 
        return solveSpace(m, n);
    }
};