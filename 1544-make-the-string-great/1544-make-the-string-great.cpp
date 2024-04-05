class Solution {
public:
    string makeGood(string s) {
        string ans = string(1, s[0]);
        int n = s.size();
        for(int i = 1; i < n; i++){
            if(ans.size() and abs(ans.back() - s[i]) == 32){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};