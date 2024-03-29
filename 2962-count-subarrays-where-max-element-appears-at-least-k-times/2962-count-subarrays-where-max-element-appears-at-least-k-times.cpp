class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_ele = *max_element(nums.begin(), nums.end());
        int max_count = 0;

        int head = 0;
        int tail = 0;
        int n = nums.size();
        long long ans = 0;
        for(head = 0; head < n; head++){
            if(nums[head] == max_ele){
                max_count++;
            }

            // this will include the current subarray
            // And the subarray that will be formed when element 
            // of right
            // side will be added


            // shrink because we are done with 
            // subarray staring from this tail
            while(max_count >= k){
                ans += n-1 - head + 1;
                if(max_ele == nums[tail]){
                    max_count--;
                }
                tail++;
            }
            
        }
        return ans;
    }
};