class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(auto &x : nums)
            sum += x;
        int t = n*(n+1);
        t/=2;
        return t - sum;
    }
};