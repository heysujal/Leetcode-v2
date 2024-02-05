class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();

        for(int i = 0; i < n; i++){
            bool unique = true;
            for(int j = 0; j < n; j++){
                if(i != j and s[j] == s[i]){
                    unique = false;
                    break;
                }
            }
            if(unique == true){
                return i;
            }
        }
        return -1;
    }
};