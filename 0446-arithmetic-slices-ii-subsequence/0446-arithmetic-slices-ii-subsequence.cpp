class Solution {
public:
    // https://www.youtube.com/watch?v=cau0JE1q_ZA&t=0s
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        // array of map
        //mp[j] gives subseq ending at j 
                    //diff, count
        unordered_map<long, int> mp[n];
        int result = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                long diff = (long)nums[i] - nums[j];
                int count_at_j = mp[j][diff]; // gives no of subseq w diff, diff
                mp[i][diff] += 1 + count_at_j; // subseq at i is always 1 greater
                result += count_at_j;
            }
        }
        return result;
    }
};