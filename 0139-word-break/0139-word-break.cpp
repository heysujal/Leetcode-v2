class Solution {
public:
    int n;
    vector<bool> dp;
    bool helper(int i, string &s, vector<string> &dict, unordered_set<string> &st){
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
        dp.resize(n+1, false);
        dp[n] = true;
        unordered_set<string> st(dict.begin(), dict.end());
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                string str = s.substr(i, j-i+1);
                if(st.find(str) != st.end()){
                    if(dp[j+1]){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};