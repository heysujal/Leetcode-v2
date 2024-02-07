class Solution {
public:
    string frequencySort(string s) {
        // index of this vector will be used as freq indicator
        unordered_map<char, int> mp;
        for(auto &ch : s){
            mp[ch]++;
        }
        vector<vector<char>> bucket(s.size() + 1);
        for(auto [ch, fq] : mp){
            bucket[fq].push_back(ch);
        }
        // iterate from last
        string ans = "";
        for(int i = s.size(); i >= 1; i--){
            for(auto &ch : bucket[i]){
                int fq = i;
                while(fq--){
                    ans.push_back(ch);
                }
            }
        }
        return ans;
    }
};