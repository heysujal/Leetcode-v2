class Solution {
public:
    bool isKDiff(vector<int> &nums, int i, int j, int k){
        return abs(nums[i] - nums[j]) <= k;
    }
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i += 3){
            if(!isKDiff(nums, i, i+2, k)){
                return {};
            }
            else{
                vector<int> v(nums.begin() + i, nums.begin() + i+3);
                ans.push_back(v);
            }
        }
        return ans;
    }
};