class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 4)
            return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(i-1 >= 0 and nums[i] == nums[i-1]) //important skip logic
                continue;
            // 3 sum starts
            int t = target - nums[i];
            int j = i+1;
            for(j = i+1; j < n ; j++){
                if(j-1 >= i+1 and nums[j] == nums[j-1])
                    continue;
                int new_t = t - nums[j];
                // apply 2 sum by using 2 ptrs
                int left = j+1;
                int right = n-1;
                while(left < right){
                    int sum = nums[left] + nums[right];
                    if(sum == new_t){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // skip duplicates
                        while(left+1 < right and nums[left+1]==nums[left]) left++;
                        left++;
                        while(right-1 > left and nums[right-1] == nums[right]) right--;
                        right--;
                    }
                    else if(sum < new_t){
                        left++;
                    }
                    else{
                        right--;
                    }
                }

            }
        }
        return ans;
    }
};