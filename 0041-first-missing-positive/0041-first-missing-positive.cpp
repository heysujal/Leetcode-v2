class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // possible missing can be from 1 to n+1;
        int n = nums.size();
        for(int i = 1; i <= n+1; i++){
            bool found = false;
            for(int j = 0; j < n; j++){
                if(nums[j] == i){
                    found = true;
                    break;
                }
            }
            if(!found){
                return i;
            }
        }
        return -1;
    }
};