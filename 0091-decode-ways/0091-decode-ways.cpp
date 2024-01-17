class Solution {
public:
    // Memo solution
    int dp[101];
    int solve(int i, string &s, int n){
        if(i == n){
            return 1; // a valid way found
        }
        if(s[i] == '0'){
            return 0; // not possible to split
        }
        if(dp[i] != -1)
            return dp[i];
        int result = solve(i+1, s, n);
        if(i+1 < n){
            if(s[i] == '1' or (s[i] == '2' and s[i+1] <= '6')){
                result += solve(i+2, s, n);
            }
        }
        return dp[i] = result;
    }

    int numDecodings(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        // if(n == 0)  don't add this check as not in constraints
        //     return 0;
        return solve(0, s, n);
    }
};