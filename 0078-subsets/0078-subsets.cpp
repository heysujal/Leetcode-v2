class Solution {
public:
    // Complexity = 2^n
    void solve(int i , vector<int> &temp, vector<int> &nums, vector<vector<int>> &ans){
        // base case
        int n = nums.size();
        if(i==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1, temp, nums, ans);
        temp.pop_back();
        // skip
        solve(i+1, temp, nums, ans);
        // pick
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, temp,nums,ans);
        return ans;
    }
};