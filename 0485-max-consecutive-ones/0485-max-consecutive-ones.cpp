class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int count = 0;
        for(int i = 0; i < n ; i++){
            if(nums[i]==1)
                count++;
            else{
                ans = max(ans, count);
                count = 0;
            }
        }
        // extra line for case [.....1 1 1 1]
        ans = max(ans, count);
        return ans;
    }
};