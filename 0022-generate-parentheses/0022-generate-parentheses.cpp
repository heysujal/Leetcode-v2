class Solution {
public:
    void solve(int open, int close, string temp, int n, vector<string> &ans){
        if(close == n){
            ans.push_back(temp);
            return;
        }
        if(open < n)
            solve(open+1, close, temp+"(", n, ans);
        if(close < open)
            solve(open, close+1, temp+")", n , ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        // Opening brackets -> 0
        // Closing Brackets -> 0
        solve(0,0,"",n,ans);
        return ans;
    }
};