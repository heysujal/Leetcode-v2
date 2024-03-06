class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int i = 0;
        while(i < n and s[i] == ' '){
            i++;
        }
        s = s.substr(i); // all leading spaces has been removed now
        int sign = +1;
        long ans = 0;
        if(s[0] == '-'){
            sign = -1;
        }

        i = (s[0] == '+' or s[0] == '-') ? 1 : 0;
        while(i < n){
            if(s[i] == ' ' or !isdigit(s[i])) break;
            ans = ans * 10 + s[i] - '0';
            if(sign == -1 and -1*ans < INT_MIN) return INT_MIN;
            if(sign == 1 and ans > INT_MAX) return INT_MAX;
            i++;
        }
        return (int)(sign * ans);
    }
};