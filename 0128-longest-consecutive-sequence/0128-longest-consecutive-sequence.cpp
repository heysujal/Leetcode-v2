class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        // for every ele check if ele+1 exists
        for(int i = 0; i < n; i++){
            int x = nums[i];
            int len = 1;
            if(st.count(x-1)){
                // this is not a starting point
                continue;
            } 
            while(st.count(x+1)){
                x++;
                len++;
            }
            longest = max(longest, len);
        }
        return longest;
    }
};