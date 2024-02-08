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
    int helperTab(int n){
        vector<int> dp(n+1, 0);
        // if amount is zero you need 0 coins
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            int min_count = 1e9;
            for(int j = 1; j*j <= i; j++){
                int mini = 1 + dp[i-j*j];
                min_count = min(min_count, mini);
            }
            dp[i] = min_count;
        }
        return dp[n];
    }
    int numSquares(int n) {
        // vector<int> dp(n+1, -1);
        // return helper(n, dp);
        return helperTab(n);
    }
};