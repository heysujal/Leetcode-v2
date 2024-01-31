class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            if(!st.empty() and nums[st.top() > nums[i]]){
                ans[i] = st.top() - i;
            }
            // if larger
            while(!st.empty() and nums[st.top()] < nums[i]){
                st.pop();
            }
            if(st.empty()){
                st.push(i);
                ans[i] = 0;
            }
            else{
                ans[i] = st.top() - i;
                st.push(i); // finally stack ke andar kuch bada hai phle se hi
            }
        }
        return ans;
    }
};