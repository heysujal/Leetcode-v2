class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0;
        int steps = 0;
        for(auto &x : nums){
            res ^= x;
        }

        for(int i = 31; i >= 0; i--){
            int op1 = res & (1 << i);
            int op2 = k & (1 << i);
            if(op1 != op2){
                steps++;
            }
        }
        return steps;
    }
};