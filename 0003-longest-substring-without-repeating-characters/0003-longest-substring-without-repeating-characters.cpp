class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int head = 0;
        int tail = 0;
        int size = s.size();
        int ans = 0;// longest substring if string is empty
        unordered_map<char, int> mp;
        for(head = 0; head < size; head++){
            mp[s[head]]++;
            while(mp[s[head]] > 1){
                mp[s[tail]]--;
                tail++;
            }
            ans = max(ans, head - tail + 1);
        }
        return ans;
    }
};