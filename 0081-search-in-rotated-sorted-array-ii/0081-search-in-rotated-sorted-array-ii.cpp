class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                return true;
            }
            // this is the only extra condition
            if(nums[low] == nums[mid] and nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }
            // check if left half is sorted

            if(nums[low] <= nums[mid]){
                // left half is sorted
                // check if target is  in range
                if(target >= nums[low] and target <= nums[mid]){
                    // lies
                    // go to left
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                // right half is sorted
                if(target >= nums[mid] and target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};