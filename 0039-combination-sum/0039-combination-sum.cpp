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
            helper(i, n, sum - nums[i], temp, nums, ans);
            temp.pop_back();
        }
        helper(i+1, n, sum, temp, nums, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        helper(0, n, target, temp, candidates, ans);
        return ans;
    }
};