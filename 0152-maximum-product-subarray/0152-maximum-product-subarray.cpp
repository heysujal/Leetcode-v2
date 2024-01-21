class Solution {
public:
    // Example -2, -18, 4, 0, 5, 6, 7, 0, 11, 16, 87
    // Core idea is that 0 divides the array into subarrays
    // and we calculate their prod and compare the max out of them
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;
        int ans = -1e9;
        // go from left to right
        for(int i = 0; i < n; i++){
            prod *= nums[i];
            ans = max(ans, prod);
            if(prod == 0){
                prod = 1;
            }
        }
        prod = 1;
        for(int i = n-1; i >= 0; i--){
            prod *= nums[i];
            ans = max(ans, prod);
            if(prod == 0){
                prod = 1;
            }
        }
        // go from right to left
        return ans;
    }
};