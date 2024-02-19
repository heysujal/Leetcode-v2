class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 and not (n & (n-1));
    }
};