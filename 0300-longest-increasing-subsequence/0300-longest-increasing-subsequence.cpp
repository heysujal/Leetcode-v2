class Solution {
public:

    int n;

    int helper(int i, int prev, vector<int> &nums, vector<vector<int>> &dp){
        if(i == n){
            return 0;
        }

        if(dp[i][prev+1] != -1){
            return dp[i][prev+1];
        }
        int op1 = 0;
        int op2 = 0;

        // skip
        op1 = helper(i+1, prev, nums, dp);
        // pick
        if(prev == -1 or nums[prev] < nums[i]){
            op2 = 1 + helper(i+1, i, nums, dp);
        }
        return dp[i][prev+1] = max(op1, op2);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return helper(0, -1, nums, dp);
    }
};