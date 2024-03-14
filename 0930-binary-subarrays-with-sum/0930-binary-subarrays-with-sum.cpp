class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp; // sum , freq
        mp[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(mp.count(sum-k)){
                count = count + mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
};