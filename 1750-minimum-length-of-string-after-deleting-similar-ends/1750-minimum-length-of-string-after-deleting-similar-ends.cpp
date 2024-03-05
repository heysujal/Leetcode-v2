class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.size() - 1;
        char ref;
        while(left < right and s[left] == s[right]){
            ref = s[left];
            while(left < right and s[left] == ref){
                left++;
            }
            while(left < right and s[right] == ref){
                right--;
            }
        }
        if(left == right and s[left] == ref){
            return 0;
        }
        return right-left+1;
    }
};