class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(auto &str : strs){
            string t = str;
            sort(t.begin(), t.end());
            mp[t].push_back(str);
        }
        for(auto &p : mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};