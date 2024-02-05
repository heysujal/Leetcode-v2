class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        int ans = INT_MAX;
        for(int i = 0; i < s.size(); i++){
            if(!mp.count(s[i])){
                mp[s[i]] = i;
            }
            else{
                mp[s[i]] = INT_MAX;
            }
        }

        for(auto &[ch, idx] : mp){
            ans = min(ans, idx);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};