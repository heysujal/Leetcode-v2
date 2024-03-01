class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count = 0;
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == '1'){
                count++;
            }
        }
        string ans(s.size(), '0');
        ans[ans.size() - 1] = '1';
        count--;
        int i = 0;
        while(count--){
            ans[i] = '1';
            i++;
        }
        return ans;
    }
};