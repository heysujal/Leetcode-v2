class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int head = 0;
        int tail = 0;
        int ans = 0;
        int max_freq = 0;
        int count[26] = {};
        for(head = 0; head < n; head++){
            int curr_ele_freq = ++count[s[head] - 'A'];
            max_freq = max(max_freq, curr_ele_freq);
            while((head - tail + 1) - max_freq > k){
                count[s[tail] - 'A']--;
                tail++;
            }
            ans = max(ans, head - tail + 1);
        }
        return ans;
    }
};