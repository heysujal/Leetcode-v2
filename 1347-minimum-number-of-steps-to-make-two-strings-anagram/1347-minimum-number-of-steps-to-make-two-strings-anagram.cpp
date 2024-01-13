class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count(26, 0);
        for(int i = 0; i < s.size(); i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        int ans = 0;
        for(auto x : count)
            if(x > 0)
                ans += x;
        return ans;
    }
};