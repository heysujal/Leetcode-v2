class Solution {
public:

    int helper(int n, vector<int> &dp){
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int min_count = INT_MAX;
        for(int i = 1; i*i <= n; i++){
            int mini = 1 + helper(n-i*i, dp);
            min_count = min(mini, min_count);
        }
        return dp[n] = min_count;
    }

    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};