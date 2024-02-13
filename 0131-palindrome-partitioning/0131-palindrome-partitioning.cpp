class Solution {
public:
    bool isPalindrome(string &s, int low, int high){
        if(low >= high)
            return true; 
        return (s[low]==s[high]) and isPalindrome(s, low+1, high-1);
    }
    void helper(int i, int n, vector<string> &temp, string &s, vector<vector<string>> &ans){
        if(i >= n){
            ans.push_back(temp);
            return;
        }
        // making cut of different lengths
        for(int len = 1; len <= n; len++){
            string str = s.substr(i, len);
            if(isPalindrome(str, 0, len-1)){
                temp.push_back(str);
                helper(i+len, n, temp, s, ans); // passing rest of the string
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n = s.size();
        vector<string> temp;
        helper(0, n, temp, s, ans);
        return ans;
    }
};