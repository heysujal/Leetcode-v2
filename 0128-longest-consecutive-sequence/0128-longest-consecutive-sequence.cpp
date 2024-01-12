class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
        int ans = 1;
         
        unordered_set<int> st(nums.begin(), nums.end());
         
        for(auto x : nums){
            if(!st.count(x-1)){
                int currele = x;
                int currlen = 1;
                while(st.count(currele+1)){
                    currlen++;
                    currele+=1;
                }
                ans = max(ans, currlen);

            }
        }

    return ans;
    }
};