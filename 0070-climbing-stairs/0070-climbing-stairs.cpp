class Solution {
public:
    int solve(int i, int n, vector<int> &dp){
        if(i > n){
            return 0;
        }
        if(i == n){
            return 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int jump1 = solve(i+1, n, dp);
        int jump2 = solve(i+2, n, dp);
        return dp[i] = jump1 + jump2;
    }
    int climbStairs(int n) {
        vector<int> dp(n, -1);
        return solve(0, n, dp);
    }
};