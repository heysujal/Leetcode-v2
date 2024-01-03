class Solution {
public:

    // Tabulation solution is all about iterating diagonally
    // short ref : https://youtu.be/biHfMygdoCE?t=1089
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // we know all strings of 1 length(i,i) in matrix are
        // palindromes
        int count = 0;

        for(int diff = 0; diff < n; diff++){
            for(int i = 0, j = diff; j < n; i++,j++){
                    if(i == j){ // string of 1 len
                        dp[i][j] = true;
                    }
                    else if(j-i == 1){  // string of 2 len(j-i+1 = 2)
                        dp[i][j] = (s[i] == s[j]);
                    }
                    else {
                        dp[i][j] = (s[i] == s[j] and dp[i+1][j-1]);
                    }
                    if(dp[i][j]){
                        count += 1;
                    } // true or false;
            }
        }
        return count;
    }
};