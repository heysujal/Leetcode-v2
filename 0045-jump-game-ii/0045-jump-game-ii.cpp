class Solution {
public:
    int n;
    int helper(int i, vector<int> &nums, vector<int> &dp){
        if(i >= n-1){
            return 0; // no need to jump
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = 1e9;
        for(int j = 1; j <= nums[i]; j++){
            ans = min(ans, 1 + helper(i+j, nums, dp));
        }
        return dp[i] = ans;
    }
    int helperTab(vector<int> &nums){
        if(n==1)
            return 0;
        vector<int> dp(n, 0);
        // dp[i] represents min steps to go from i to n-1
        dp[n-1] = 0;
        dp[n-2] = 1;

        for(int i = n-2; i >= 0; i--){
            int ans = 1e9;
            for(int j = 1; j <= nums[i]; j++){
                if(i + j < n){
                    ans = min(ans, 1 + dp[i+j]);
                }
            }
            dp[i] = ans;
        }
        return dp[0];
    }
    int jump(vector<int>& nums) {
        n = nums.size();
        // vector<int> dp(n, -1);
        // return helper(0, nums, dp);
        return helperTab(nums);
    }
};