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
    int jump(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n, -1);
        return helper(0, nums, dp);
    }
};