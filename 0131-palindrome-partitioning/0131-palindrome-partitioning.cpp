class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;

    bool isPalindrome(int low, int high, string &s){
        while(low <= high){
            if(s[low] != s[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    void helper(int idx, string &s){
        int n = s.size();
        if(idx == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = idx; i < n; i++){
            if(isPalindrome(idx, i, s)){
                temp.push_back(s.substr(idx, i-idx+1));
                helper(i+1, s);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        helper(0, s);
        return ans;
    }
};