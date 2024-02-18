class Solution {
public:
    int n;
    vector<int> dp;
    bool helper(int i, string &s, vector<string> &dict, 
    unordered_set<string> &st){
        if(i == n){
            return true;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        for(int j = i; j < n; j++){
            string str = s.substr(i, j-i+1);
            if(st.find(str) != st.end()){
                if(helper(j+1, s, dict, st)){
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& dict) {
        n = s.size();
        dp.resize(n, -1);
        unordered_set<string> st(dict.begin(), dict.end());
        return helper(0, s, dict, st);
    }
};