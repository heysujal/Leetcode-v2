class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // apply cyclic sort
        // idea nums[i] should be present at index nums[i]-1
        // 1 should be present at index 1-1 = 0

        int i = 0;
        int n = nums.size();
        vector<int> ans;
        while(i < n){
            if(nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
            else
                i++;
        }
        for(int i = 1; i <= n; i++){
            if(i != nums[i-1])
                ans.push_back(i);
        }
        return ans;
    }
};