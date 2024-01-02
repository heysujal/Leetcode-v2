class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        //1 <= nums[i] <= n
        vector<int> mp(n+1);
        vector<vector<int>> ans;
        // elements should go in its freq th row

        for(int i = 0; i < n; i++){
            int freq = mp[nums[i]];
            // 0(freq) == 0 (empty array)
            if(freq == ans.size()){
                ans.push_back({});
            }
            ans[freq].push_back(nums[i]);
            mp[nums[i]]++;
        }
        return ans;
    }
};