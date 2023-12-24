class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string possible_string1 = "";
        string possible_string2 = "";
        char flag1 = '0';
        char flag2 = '1';
        for(int i=0; i < n; i++){
            possible_string1.push_back(flag1);
            possible_string2.push_back(flag2);
            swap(flag1, flag2);
        }

        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != possible_string1[i])
                count1++;
            if(s[i] != possible_string2[i])
                count2++;
        }
        return min(count1, count2);
    }
};