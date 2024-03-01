class Solution {
public:
    // in the deque decreasing order is being maintained
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;

        for(int i = 0; i < n; i++){
            // make the window size equal to k
            // by keep only prev2 + curr elements in deque
            //    x   i
            // 1 -1 2 0 8  , k = 2, 
            // remove all from and before index x = i - k
            while(!dq.empty() and dq.front() <= i - k){
                // this way size of window will be k
                dq.pop_front();
            }

            // size is now k
            // try to store new max
            // also remove those who can never be max
            while(!dq.empty() and nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            // by this time either dq will be empty OR
            // will be having greater elements in it
            dq.push_back(i);
            if( i >= k-1){ // index reaches window size
                // windows are being formed from now on
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};