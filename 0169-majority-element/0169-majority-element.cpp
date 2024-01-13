class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = INT_MIN;
        int count = 0;
        for(int num : nums){
            if(count == 0){
                candidate = num;
                count = 1; // new candidate
            }
            else if(num == candidate){
                count++; // same
            }
            else{
                count--;
            }
        }
        return candidate;
    }
};