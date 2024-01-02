class Solution {
public:
    // Ref : https://www.youtube.com/watch?v=n_kL8BkURVA

    // Memo -> Repeating subproblems
    //      0 1 2 3 4 5 6 
    // s = "a a a a a a a"

    // for solve(0, 5)
    // isPalindromeMemo(0, 5) calls isPalindromeMemo(1, 4) calls isPalindromeMemo(2, 3)
    
    // for solve(1, 4)
    // isPalindromeMemo(1, 4) calls isPalindromeMemo(2, 3)

    int isPalindromeMemo(int i, int j, string &s, vector<vector<int>> &dp){
        if(i >= j)
            return true;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = (s[i] == s[j]) and isPalindromeMemo(i+1, j-1, s, dp);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int startIdx = -1;
        int maxLen = 0; 
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                // s.substr(i, j-i+1) can give the substring here
                // if required

                if(isPalindromeMemo(i, j , s, dp)){
                    int len = j - i + 1;
                    if(len > maxLen){
                        startIdx = i;
                        maxLen = len;
                    }
                }
            }
        }
        return s.substr(startIdx, maxLen);
    }
};