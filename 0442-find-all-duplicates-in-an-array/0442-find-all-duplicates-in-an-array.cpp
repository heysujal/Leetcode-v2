class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        vector<int> ans;
        while(i < n){
            if(nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
            else
                i++;
        }
        for(int i=1; i<=n; i++){
            if(i!=nums[i-1]){
                ans.push_back(nums[i-1]);
            }
        }
        return ans;    
    }
};