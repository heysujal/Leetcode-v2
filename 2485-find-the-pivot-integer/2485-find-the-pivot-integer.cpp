class Solution {
public:
    int pivotInteger(int n) {
        int total = (n * (n+1))/2;
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += i;
            if(sum == (total + i - sum)){
                return i;
            }
        }
        return -1;
    }
};