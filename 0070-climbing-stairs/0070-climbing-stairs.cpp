class Solution {
public:
    // fibonacci pattern
    // in example 1, n=2
    // the question starts from 0th stair
    int climbStairs(int n) {
        if(n == 1 or n == 2)
            return n;
         int s = 1;
         int f = 2;
         for(int i = 3; i <= n; i++){
            int t = f + s;
            s = f; 
            f = t;
         }
         return f;
    }
};