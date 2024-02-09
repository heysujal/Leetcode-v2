class Solution {
public:
    // gives longest substring possible expanding from i, j
    string expandAroundCentre(int i, int j, string &s){
        int n = s.size();
        string ans = "";
        while((i >= 0 and j < n) and s[i] == s[j]){
            if(ans.size() < j-i+1){
                ans = s.substr(i, j-i+1);
            }
            i--;
            j++;
        }
        return ans;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            string odds = expandAroundCentre(i, i, s);
            string evens = expandAroundCentre(i, i+1, s);
            // for every starting we have evens and odds palindromes
            if(ans.size() < evens.size()){
                ans = evens;
            }
            if(ans.size() < odds.size()){
                ans = odds;
            }
        }
        return ans;
    }
};