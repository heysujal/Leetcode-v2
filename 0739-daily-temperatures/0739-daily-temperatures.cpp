class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0); 
        stack<int> st; // for storing the indices to keep track of greater elements
        for(int i = n-1; i >= 0; i--){
            if(!st.empty() and nums[i] < nums[st.top()]){
                ans[i] = st.top()-i;
            }
            while(!st.empty() and (nums[i] >= nums[st.top()]))
                st.pop();
            // if stack becomes empty then what?
            if(st.empty()) // kuch mat kro
                ans[i] = 0;
            else // we have a warmer day at stack ka top
                ans[i] = st.top()-i; // also save current bcoz it can be first warmer for rest
            st.push(i);
        }
        return ans;
    }
};