class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int i = 0;
       int j = 0;
       int n = nums.size();
       for(int i = 0; i < n; i++){
           if(nums[i] != val){
               nums[j] = nums[i];
               j++;
           }
       }
        return j;
    }
};