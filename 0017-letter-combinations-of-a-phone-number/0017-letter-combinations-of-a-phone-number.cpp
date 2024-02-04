class Solution {
public:
    vector<string> dir = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int n;
    void helper(int i, string digits, string temp, vector<string> &ans){
        if(i == n){
            ans.push_back(temp);
            return;
        }
        char digit = digits[i];
        int idx = digit - '0';
        string alphabets = dir[idx];
        int len = alphabets.size();
        for(int k = 0; k < len; k++){
            temp.push_back(alphabets[k]);
            helper(i+1, digits, temp, ans);
            temp.pop_back();
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        if(n == 0)
            return {};
        vector<string> ans;
        string temp;
        helper(0, digits, temp, ans);
        return ans;
    }
};