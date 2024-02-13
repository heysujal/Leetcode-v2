class Solution {
public:
    void helper(int i, int n, vector<int> temp, vector<int> &nums, set<vector<int>> &ans){
        if(i == n){
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        helper(i+1, n, temp, nums, ans);
        temp.pop_back();
        helper(i+1, n, temp, nums, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();
        helper(0, n, {}, nums, st);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans; 
    }
};