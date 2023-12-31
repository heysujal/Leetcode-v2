class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int len = INT_MIN;
        int n = s.size();
        vector<int> firstIdx(26, -1);
        vector<int> lastIdx(26, -1);
        for(int i = n-1; i >= 0; i--){
            if(lastIdx[s[i] - 'a'] != -1)
                continue;
            lastIdx[s[i] - 'a'] = i;
        }
        for(int i = 0; i < n; i++){
            if(firstIdx[s[i] - 'a'] == -1)
                firstIdx[s[i] - 'a'] = i;
            int f = firstIdx[s[i] - 'a'];
            int l = lastIdx[s[i] - 'a'];
            len = max(len, l - f - 1);    
        }
        return len;
    }
};