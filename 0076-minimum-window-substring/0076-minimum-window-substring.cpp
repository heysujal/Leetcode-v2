class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        string ans="";
        unordered_map<char, int> mp;

        for(auto &ch : t){
            mp[ch]++;
        }

        int requiredCount = t.size();
        int head = 0;
        int tail = 0;
        int minStart = 0;
        int minWindow = INT_MAX;

        for(head = 0; head < n; head++){
            char ch = s[head];
            if(mp[ch] > 0){
                requiredCount--;
            }
            mp[ch]--;
            while(requiredCount == 0){
                if(minWindow > head - tail + 1){
                    minWindow = head - tail + 1;
                    minStart = tail;
                }
                // decrease the tail value
                char ch = s[tail];
                mp[ch]++;
                if(mp[ch] > 0){
                    requiredCount++;
                }
                tail++;
            }
        }
        return minWindow == INT_MAX ? "" : s.substr(minStart, minWindow);
    }
};