class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
        int ans = 1;
        int len = 1;
        sort(nums.begin(), nums.end());
        for(int i  = 1 ; i < nums.size() ; i++){
            
            if(nums[i] == nums[i-1] + 1){
                len++;
                ans = max(ans, len);             
            }else if(nums[i]==nums[i-1]){
                continue;
            }else{
                len = 1;
            }
        }
    return ans;
    }
};