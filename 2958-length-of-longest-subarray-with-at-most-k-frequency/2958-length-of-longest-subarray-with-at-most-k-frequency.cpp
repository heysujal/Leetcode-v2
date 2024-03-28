class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int head = 0;
        int tail = 0;
        int n = nums.size();
        int ans = 1;
        for(head = 0; head < n; head++){
            mp[nums[head]]++;
            while(mp[nums[head]] > k){
                mp[nums[tail]]--;
                tail++;
            }
            ans = max(ans, head - tail + 1);
        }
        return ans;
    }
};