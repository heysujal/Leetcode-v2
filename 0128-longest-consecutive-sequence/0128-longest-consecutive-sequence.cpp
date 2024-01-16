class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for(auto &x : nums){
            st.insert(x);
        }
        for(auto &t : st){
            if(!st.count(t-1)){
                // this is starting of sequence
                int curr = 1;
                int x = t;
                while(st.count(x+1)){
                    curr++;
                    x++;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};