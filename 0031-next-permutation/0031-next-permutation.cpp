class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int gola_index = -1;
        for(int i = n-1; i >= 1; i--){
            if(nums[i-1] < nums[i]){
                gola_index = i-1;
                break;
            }
        }
        if(gola_index != -1){
            int swap_index = -1;
            for(int i = n-1; i > gola_index; i--){
                if(nums[gola_index] < nums[i]){
                    swap_index = i;
                    break;
                }
            }
            swap(nums[gola_index], nums[swap_index]);
            // reverse nums from gola_index + 1 till end
        }
        reverse(nums.begin() + gola_index+1, nums.end());
    }
};