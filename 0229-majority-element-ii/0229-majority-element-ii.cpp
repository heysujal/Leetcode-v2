class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // there is no guarantee if element must exist
        int n = nums.size();
        int count1 = 0;
        int candidate1 = INT_MIN;
        int count2 = 0;
        int candidate2 = INT_MIN;
        for(int i = 0; i < n; i++){
            if(nums[i] == candidate1){
                count1++;
            }
            else if(nums[i] == candidate2){
                count2++;
            }
            else if(count1 == 0){
                candidate1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                candidate2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        // Verification 
        int maj = n/3;
        count1 = 0;
        count2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == candidate1)
                count1++;
            if(nums[i] == candidate2)
                count2++;
        }
        vector<int> ans;
        if(count1 > maj)
            ans.push_back(candidate1);
        if(count2 > maj)
            ans.push_back(candidate2);
        return ans;
    }
};