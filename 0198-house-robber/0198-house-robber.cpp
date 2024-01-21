class Solution {
public:
    int n;
    int helperMemo(int i, vector<int> &nums, vector<int> &dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int rob = nums[i] + helperMemo(i+2, nums, dp);
        int skip = 0 + helperMemo(i+1, nums, dp);
        return dp[i] = max(rob, skip);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n, -1);
        return helperMemo(0, nums, dp);
    }
};