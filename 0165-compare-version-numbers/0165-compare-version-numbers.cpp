class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i = 0;
        int j = 0;
        int x = 0;
        int y = 0;
        int m = v1.size();
        int n = v2.size();
        while(i < m or j < n){
            while(i < m and v1[i] != '.'){
                x = x*10 + (v1[i] - '0');
                i++;
            }
            while(j < n and v2[j] != '.'){
                y = y*10 + (v2[j] - '0');
                j++;
            }
            if(x > y){
                return 1;
            }
            if(x < y){
                return -1;
            }
            i++;
            j++;
            x = 0;
            y = 0;
        }
        return 0;
    }
};