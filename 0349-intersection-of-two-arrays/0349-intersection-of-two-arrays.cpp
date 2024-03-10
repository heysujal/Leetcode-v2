class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> mp;
        for(auto &x : nums1){
            mp[x] = true;
        }
        unordered_set<int> st;
        for(auto &x : nums2){
            if(mp.find(x) != mp.end()){
                st.insert(x);
            }
        }
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};