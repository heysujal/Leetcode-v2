class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int i = 0; int j = 0;
        // i for >0 and j for < 0
        for(int i = 0,j = 0; i < n and j < n; i++, j++){
            while(nums[i] < 0){
                i++;
            }
            while(nums[j] > 0){
                j++;
            }
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
        }
        return ans;
    }
};