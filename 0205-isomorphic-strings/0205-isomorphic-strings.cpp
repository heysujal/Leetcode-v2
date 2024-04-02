class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        int i = 0;
        int n = t.size();
        while(i < n){
            if(mp.count(s[i])){
                if(mp[s[i]] != t[i]){
                    return false;
                }
            }
            mp[s[i]] = t[i];
            i++;
        }
        return true;
    }
};