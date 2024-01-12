class Solution {
public:

    bool halvesAreAlike(string s) {
        int n = s.size() / 2;
        string s1 = s.substr(0, n);
        string s2 = s.substr(n, n);
        unordered_map<char, int> mp;
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for(auto &ch : s1)
            mp[ch]++;
        for(auto &ch : s2)
            mp[ch]--;
        for(auto &ch : vowels){
            if(mp[ch] != 0)
                return false;
        }
        return true;
    }
};