class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle) != string::npos){
            int idx = haystack.find(needle);
            return idx;
        }
        return -1;
    }
};