class Solution {
public:
    int expandAroundCentre(int i, int j, string &s){
        int n = s.size();
        int count = 0;
        while((i >= 0 and j < n) and (s[i] == s[j])){
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int odd = expandAroundCentre(i, i, s);
            int even = expandAroundCentre(i, i+1, s);
            ans += (odd + even);
        }
        return ans;
    }
};