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
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        vector<int> dp(n, -1);
        return helperMemo(0, nums, dp);
    }
};