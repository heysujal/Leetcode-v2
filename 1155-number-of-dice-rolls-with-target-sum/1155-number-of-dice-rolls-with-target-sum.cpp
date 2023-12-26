class Solution {
public:
    const int mod = 1e9 + 7;
    int solve(int i, int n, int k, int target, vector<vector<int>> &dp){
        if(i == n){
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

    int numRollsToTarget(int n, int k, int target) {
        // starting with 0th die
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return solve(0, n, k, target, dp);
    }
};