class Solution {
public:
   
    int isPalindrome(int i, int j, string &s){
        if(i >= j)
            return true;
        return (s[i] == s[j]) and isPalindrome(i+1, j-1, s);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int startIdx = -1;
        int maxLen = 0; 
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPalindrome(i, j , s)){
                    if(j-i+1 > maxLen){
                        startIdx = i;
                        maxLen = j-i+1;
                    }
                }
            }
        }
        return s.substr(startIdx, maxLen);
    }
};