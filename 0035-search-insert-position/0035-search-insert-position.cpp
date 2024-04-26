class Solution {
public:
    // Lower Bound
    // find smallest index for which x <= arr[index]
    // So, we try to store potential answer
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        if(target < nums[0]){
            return 0;
        }
        else if(target > nums[n-1]){
            return n;
        }

        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(target <= nums[mid]){
                // store potential answer
                // look for smaller index
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};