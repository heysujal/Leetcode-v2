class Solution {
public:
    const int mod = 1e9 + 7;
    int solve(int i, int n, int k, int target, vector<vector<int>> &dp){
        if(i == n){ // we are out of dice here 
            return target == 0 ? 1 : 0;
        }
        if(dp[i][target] != -1)
            return dp[i][target];
        int ways = 0;
        for(int face = 1; face <= k; face++){
            if(target - face >= 0)
                ways += solve(i+1, n, k, target - face, dp);
                ways = ways % mod;
        }
        return dp[i][target] = ways;
    }

    int solveTab(int n, int k, int target){
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        // what is dp[i][j] here?
        // dp[i][j] is ways to form target j using exactly i..n-1 dice
        // here this means if you can form target using a single last die
        // so, only 1, 2, 3, 4, 5, and 6 can be formed with one die
        // filling up the base case
        for(int face = 1; face <= target; face++){
            if(face >= 1 and face <= k)
                dp[n-1][face] = 1;
        }

        for(int i = n-2; i >= 0; i--){
            for(int t = 0; t <= target; t++){
                for(int face = 1; face <= k; face++){
                    if(t - face >= 0){
                        int ways = dp[i+1][t-face];
                        dp[i][t] += ways;
                        dp[i][t] = dp[i][t] % mod;
                    }
                }
            }
        }
        return dp[0][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        // starting with 0th die
        // vector<vector<int>> dp(n, vector<int>(target+1, -1));
        // return solve(0, n, k, target, dp);
        return solveTab(n, k, target);
    }
};