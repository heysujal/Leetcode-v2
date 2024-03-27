class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // brute force
        // make all subarrays
        int n = nums.size();
        set<vector<int>> st;
        int count = 0;
        for(int i = 0; i < n; i++){
            int prod = 1;
            for(int j = i; j < n; j++){
                // the below loop iterates over each subarray
                prod *= nums[i];
                if(prod < k){
                    vector<int> v;
                    v.insert(v.end(), nums.begin() + i, nums.begin() + i + j);
                    st.insert(v);
                }
                else{
                    break;
                }
            }
        }
        return st.size();
    }
};