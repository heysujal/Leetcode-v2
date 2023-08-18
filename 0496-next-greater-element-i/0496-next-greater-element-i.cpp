class Solution {
public:
    vector<int> ans;
    void nextGE(vector<int> &nums2){
        stack<int> st;
        int n = nums2.size();
        ans.resize(n);
        for(int i = n - 1 ; i >= 0 ;i--){      
            while(!st.empty() and nums2[i] >= st.top()){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
                st.push(nums2[i]);
            }
            else{
                ans[i] = st.top();
                st.push(nums2[i]);
            }
        }
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        unordered_map<int,int> mp; // value, index for nums2
        int k = 0;
        for(auto &x : nums2)
            mp[x] = k++;
        nextGE(nums2);
        for(int i = 0; i < nums1.size(); i++){
            int idx = mp[nums1[i]];
            v.push_back(ans[idx]);
        }
        return v;
    }
};