class Solution {
public:
    // why sorting?
    // to be able to remove duplicate by skipping them
    // it is required if even if you use a set
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            // we DON'T skip the first duplicate, only later ones
            if(i > 0 and nums[i-1] == nums[i]) continue;
            // apply 2 ptrs
            int target = -(nums[i]);
            int low = i+1;
            int high = n-1;
            while(low < high){
                int sum = nums[low] + nums[high];
                if(sum == target){
                    ans.push_back({nums[i], nums[low], nums[high]});
                    // skip the duplicates
                    while(low + 1 < high and nums[low+1] == nums[low]){
                        low++;
                    }
                    while(high - 1 > low and nums[high-1] == nums[high]){
                        high--;
                    }
                    // skip the last duplicate as well.
                    low++;
                    high--;
                }
                else if(sum > target){
                    high--;
                }
                else{
                    low++;
                }
            }
        }
        return ans;
    }
};