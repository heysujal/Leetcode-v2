class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Missing POSITIVE([1,n])
        int i = 0;
        int n = nums.size();
        while(i<n){
            // Try avoiding any +1 and -1 to avoid overflow
            // nums[i]-1 >= 0 => nums[i] >= 1 => nums[i] > 0
            // nums[i]-1 < n => nums[i] < n+1 => nums[i] <= n
            if(nums[i] > 0 and nums[i] <= n and nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
            else
                i++;
        }
        // Array should be like this 1,2,3,-1,5,0
        for(int i = 1 ; i <= n ; i++)
            if(i != nums[i-1])
                return i;
        // Test case : [1]
        // 2 is missing
        return n+1;
    }
};