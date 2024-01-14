class Solution {
public:
    int n;
    bool helperMemo(int i, vector<int> &nums, vector<int> &dp){
        if(i == n-1)
            return true;
        if(i >= n)
            return false;
        if(dp[i] != -1)
            return dp[i];
        int jumpRange = nums[i];
        for(int jump = 1; jump <= jumpRange; jump++){
            if(helperMemo(i+jump, nums, dp))
                return dp[i] = true;
        }
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n, -1);
        return helperMemo(0, nums, dp);
    }
};