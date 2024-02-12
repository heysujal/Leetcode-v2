class Solution {
public:
    // Voting Algo
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(count == 0){
                candidate = nums[i];
                count++;
            }
            else if(nums[i] == candidate){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
};