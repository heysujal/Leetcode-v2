class Solution {
public:
    // dnf sort
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0; // points at 0s
        int mid = 0; // points at 1s
        int high = n - 1; // points at 2s
        
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        return;
    }
};