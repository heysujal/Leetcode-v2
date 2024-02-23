class Solution {
public:
    // bucket sort
    // using a map to count freq
    // making a vector of vector bucket(n+1) size
    // filling bucket with using freq as indices and value as element
    // which means bucket[i] vector has elements which has freq i
    // now, iterate backwards to find non-empty vectors with high freq
    // and also decrease k
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto &x : nums){
            mp[x]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for(auto &pair : mp){
            bucket[pair.second].push_back(pair.first);
        }
        // i = n because bucket has a size of n+1
        vector<int> ans;
        for(int i = n; i >= 0; i--){
            if(bucket[i].size() == 0){
                continue;
            }
            while(size(bucket[i]) > 0 and k){
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return ans;
    }
};