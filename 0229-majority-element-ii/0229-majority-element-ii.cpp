class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = nums.size();
        // Traverse through array elements and
        // count frequencies
        for (int i = 0; i < n; i++){
             mp[nums[i]]++;
        }
        for(auto p : mp){
            if(p.second > n/3)
                ans.push_back(p.first);
        }
        return ans;
    }
};