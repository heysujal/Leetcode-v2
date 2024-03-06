class Solution {
public:

    string common(string p, string q){
        int n = min(p.size(), q.size());
        string res = "";
        int i = 0;
        while(i < n){
            if(p[i] == q[i]){
                res.push_back(p[i]);
            }
            else{
                break;
            }
            i++;
        }
        return res;
    }

    string longestCommonPrefix(vector<string>& strs) {
        // assuming the first string to be ans
        string ans = strs[0];
        // now we try to find common with other strings
        for(int i = 1; i < strs.size(); i++){
            ans = common(ans, strs[i]);
        }
        return ans;
    }
};