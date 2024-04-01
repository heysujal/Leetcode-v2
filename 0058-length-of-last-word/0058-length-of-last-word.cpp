class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int n = s.size();

        for(int i = n-1; i >= 0; i--){
            if(s[i] == ' '){
                continue;
            }
            while(i >= 0){
                if(s[i] != ' '){
                    len++;
                }
                else{
                    return len;
                }
                i--;
            }
        }
        return len;
    }
};