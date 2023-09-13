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
        // by this time order should be like 1 2 3 4 .....N X(this X is repeated number)
        // so the wrong number should be present at end (Why?)
        // Range is 1 to N but there are n+1 numbers in total
        // one number is being repeated one or many number of times
        // so more number would be lost 
        // the repeated number will take the place of loss numbers
        // and also would be present at the end
        return nums[n-1];
    }
};