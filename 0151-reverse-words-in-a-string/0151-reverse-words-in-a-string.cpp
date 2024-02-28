class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == ' ') continue;
            else{
                int j = i;
                while(j >= 0 and s[j] != ' '){
                    j--;
                }
                j++;
                string str = s.substr(j, i-j+1);
                ans += str + " ";
                i = j;
            }
        }
        ans.pop_back();
        return ans;
    }
};