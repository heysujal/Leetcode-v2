class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp; // num2[i] -> ans[i]
        stack<int> st;
        for(int i = nums2.size()-1; i >= 0; i--){
            if(st.empty()){
                mp[nums2[i]] = -1;
                st.push(nums2[i]);
            }else{
                // non-empty
                while(!st.empty() and st.top() <= nums2[i])
                    st.pop();
                if(st.empty()){
                    mp[nums2[i]] = -1;
                    st.push(nums2[i]);
                }
                else{
                    mp[nums2[i]] = st.top();
                    st.push(nums2[i]);
                }
            }
        }
        int n = nums1.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};