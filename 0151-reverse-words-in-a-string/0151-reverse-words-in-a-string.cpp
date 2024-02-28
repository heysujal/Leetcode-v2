class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                continue;
            }
            else{
                int start = i;
                while(start < s.size() and s[start] != ' '){
                    start++;
                }
                start--;
                int len = start - i + 1;
                string str = s.substr(i, len);
                v.push_back(str);
                i = start;
            }
        }
        string ans = "";
        for(int i = v.size()-1; i >= 0; i--){
            ans += v[i] + " ";
        }
        ans.pop_back();
        return ans;
    }
};