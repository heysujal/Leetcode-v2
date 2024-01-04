class Solution {
public:
// codeStory : https://www.youtube.com/watch?v=CboKBIpo640
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // first find the right candidate/(i-1)th elements or gola
        int gola_index = -1;

        // go from right to left
        for(int i = n-1; i > 0; i--){
            if(nums[i-1] < nums[i]){
                gola_index = i-1;
                break;
            }
        }

        if(gola_index != -1){
            // swap_idx will be just greater element on right side
            int swap_index = gola_index; // assume, pro: handles when no greater found
            // to find first greater we traverse from right till gola + 1
            for(int j = n-1; j >= gola_index + 1; j--){
                if(nums[gola_index] < nums[j]){
                    swap_index = j;
                    break;
                }
            }
            swap(nums[gola_index], nums[swap_index]);
        }
        // reverse from [i..end]                        
        reverse(nums.begin() + gola_index + 1, nums.end());
    }
};