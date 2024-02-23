class Solution {
public:

    int partition(vector<int> &nums, int L, int R){
        int P = nums[L];
        int i = L+1;
        int j = R;
        // Good Order nums[i](all greater) > P > nums[j](all smaller)
        while(i <= j){
            if(nums[i] < P and nums[j] > P){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if(nums[i] >= P){
                i++;
            }
            if(P >= nums[j]){
                j--;
            }
        }
        swap(nums[L], nums[j]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int L = 0;
        int R = n-1;
        int pivot_idx = 0; // assuming first element as pivot
        
        // k-th largest means nums[k-1] 
        // in decending order after partitioning
        while(true){ // i have no clue when this suffering will end

            pivot_idx = partition(nums, L , R);
            if(pivot_idx == k-1){
                return nums[pivot_idx];
            }
            else if(pivot_idx > k-1){
                // wanted 2nd but got 4th largest, so shrink
                R = pivot_idx - 1;
            }
            else{
                L = pivot_idx + 1;
            }
        }
        return nums[pivot_idx];
    }
};