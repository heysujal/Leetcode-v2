class Solution {
public:
    void helper(int i, int n, vector<int> temp, vector<int> &nums, vector<vector<int>> &ans){
        if(i == n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        helper(i+1, n, temp, nums, ans);
        temp.pop_back();
        // it is important that you never skip the first occurence
        // or else you will lose on some subsets
        while(i+1 < n and nums[i] == nums[i+1]){
            i++;
        }
        helper(i+1, n, temp, nums, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        helper(0, n, {}, nums, ans);
        return ans; 
    }
};