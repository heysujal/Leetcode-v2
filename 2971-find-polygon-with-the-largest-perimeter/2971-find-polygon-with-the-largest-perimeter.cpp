class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        long long ans = INT_MIN;;
        sort(nums.begin(), nums.end());
        vector<long long> pre(n, 0); // stores sum before i-th element
        pre[0] = 0;
        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1] + nums[i-1];
        }
        for(int i = n-1; i >= 0; i--){
            if(nums[i] < pre[i]){
                long long perimeter = pre[i] + nums[i];
                ans = max(ans, perimeter);
            }
        }
        return ans == INT_MIN ? -1 : ans;
    }
};