class Solution {
public:

    void helper(int open, int close, int n, string temp, vector<string> &ans){
        if(temp.size() == 2*n){ // or close == n
            ans.push_back(temp);
            return;
        }
        if(open < n){
            helper(open+1, close, n, temp + '(', ans);
        }
        if(close < open){
            helper(open, close+1, n, temp + ')', ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(0,0, n, "", ans);
        return ans;
    }
};