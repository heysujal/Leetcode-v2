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
    int helperTab(vector<int> &nums){
        vector<int> dp(n, 0);
        // dp[i] represents money from ith...n-1th.. house
        // that can be robbed at max
        dp[n-1] = nums[n-1];// only single house to rob
        dp[n-2] = max(nums[n-1], nums[n-2]); // max of last two house
        // From helperMemo, we see
        // to find dp[i] we use dp[i+1] and dp[i+2]

        for(int i = n-3; i >= 0; i--){
            int rob = nums[i] + dp[i+2];
            int skip = 0 + dp[i+1];
            dp[i] = max(rob, skip);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        // vector<int> dp(n, -1);
        // return helperMemo(0, nums, dp);
        return helperTab(nums);
    }
};