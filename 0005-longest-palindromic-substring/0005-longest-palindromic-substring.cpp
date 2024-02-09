class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int diff = 0; diff < n; diff++){
            for(int i = 0, j = diff; i < n; i++, j++){
                if(diff == 0){
                    dp[i][j] = true;
                }
                else if(diff == 1){
                    dp[i][j] = (s[i] == s[j]);
                }
                else{
                    dp[i][j] = (s[i] == s[j]) and dp[i+1][j-1];
                }
                if(dp[i][j] and (j-i+1) > ans.size()){
                    ans = s.substr(i, j-i+1);
                }
            }
        }
        return ans;
    }
};