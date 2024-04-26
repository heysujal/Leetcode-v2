class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                return mid;
            }
            // check if left half is sorted
            if(nums[low] <= nums[mid]){
                if(target >= nums[low] and target <= nums[mid]){
                    // belongs here
                    high = mid;
                }
                else{
                    low = mid + 1;
                }
            }

            else{
                // right half is sorted 
                if(target >= nums[mid] and target <= nums[high]){
                    // lies within this range
                    low = mid;
                }
                else{
                    high = mid - 1;
                }
            }
        } 
        return -1;
    }
};