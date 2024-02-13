class Solution {
public:
    void helper(int i, int n, int sum, vector<int> &temp, vector<int> &nums, vector<vector<int>> &ans){
        if(i >= n){
            if(sum == 0){
                ans.push_back(temp);
            }
            return;
        }
        if(sum >= nums[i]){
            temp.push_back(nums[i]);
            helper(i+1, n, sum - nums[i], temp, nums, ans);
            temp.pop_back();
        }
        while(i+1 < n and (nums[i] == nums[i+1])){
            i++;
        }
        helper(i+1, n, sum, temp, nums, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        helper(0, n, target, temp, nums, ans);
        return ans;
    }
};