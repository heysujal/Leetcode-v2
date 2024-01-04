class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int gola_index = -1;
        int n = nums.size();
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                gola_index = i;
                break;
            }
        }
        if(gola_index == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        // swap w first greater from right. search Range [gola_index+1.....end]
        for(int i = n-1; i > gola_index; i--){
            if(nums[i] > nums[gola_index]){
                swap(nums[i], nums[gola_index]);
                break;
            }
        }
        reverse(nums.begin() + gola_index + 1, nums.end());
    }
};