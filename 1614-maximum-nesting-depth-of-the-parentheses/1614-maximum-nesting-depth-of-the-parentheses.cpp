class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int i = 0;
        int len = 0;

        while(i < s.size()){
            if(s[i] == '('){
                len++;
                ans = max(ans, len);
            }
            else if(s[i] == ')'){
                len--;
            }
            i++;
        }
        return ans;
    }
};