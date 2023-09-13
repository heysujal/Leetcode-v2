class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while(i < n){
            // 1 should be present at index 0 in sorted order
            if(nums[i]-1 < n and nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
            else
                i++;
        }
        // by this time order should be like 1 2 3 4 .....
        // iterating over range
        return nums[n-1];
    }
};