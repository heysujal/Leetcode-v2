class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        char flag1 = '0';
        char flag2 = '1';
        int count1 = 0;
        int count2 = 0;
        for(int i=0; i < n; i++){
            if(s[i] != flag1) count1++;
            if(s[i] != flag2) count2++;
            swap(flag1, flag2);
        }
        return min(count1, count2);
    }
};