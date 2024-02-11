class Solution {
public:
    void helper(int i, vector<int> &temp, vector<vector<int>> &ans, vector<int> &nums){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }
        // pick 
        temp.push_back(nums[i]);
        helper(i+1, temp, ans, nums);
        temp.pop_back();
        // skip
        helper(i+1, temp, ans, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0, temp, ans, nums);
        return ans;
    }
};