class Solution {
public:

    int modBS(vector<int> &nums, int target, bool firstOcc){
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                ans = mid;
                if(firstOcc){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else if(target > nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {modBS(nums, target, true), modBS(nums, target, false)};
    }
};