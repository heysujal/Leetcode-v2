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
        // here it is important to use this way
        // because we are trying to partition and NOT creating
        // some subsequence, so we need to have all characters
        // that too from starting
        // cut = 0 means giving whole string away
        // cut = 1 means ["char0", "......restChars"]
        // cut = 2 means ["char0char1", ".....restChars"]
        for(int cut = i; cut < n; cut++){
            // you make cuts here on the original string
            // and apply cuts on rest of the partition by recursion
            string str = s.substr(i, cut-i+1);
            if(isPalindrome(str, 0, cut-i)){
                temp.push_back(str);
                helper(cut+1, n, temp, s, ans); // passing rest of the string
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