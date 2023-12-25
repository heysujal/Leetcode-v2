class Solution {
public:

    int solve(int i, string &s){
        int n = s.size();
        if(i == n)
            return 1;
        if(s[i] == '0')
            return 0; 
        int op1 = solve(i+1, s);
        int op2 = 0;
        if((i+1 < n) and (s[i]=='1' or (s[i] == '2' and s[i+1] <= '6')))
            op2 += solve(i+2, s);
        return op1 + op2;
    }
    int solveMemo(int i, string &s, vector<int> &dp){
        int n = s.size();
        if(i == n)
            return 1;
        if(s[i] == '0')
            return 0; 
        if(dp[i] != -1)
            return dp[i];
        int op1 = solveMemo(i+1, s, dp);
        int op2 = 0;
        if((i+1 < n) and (s[i]=='1' or (s[i] == '2' and s[i+1] <= '6')))
            op2 += solveMemo(i+2, s, dp);
        return dp[i] = op1 + op2;
    }

    int numDecodings(string s) {
        // return solve(0, s);
        vector<int> dp(s.size(), -1);
        return solveMemo(0, s, dp);
    }
};