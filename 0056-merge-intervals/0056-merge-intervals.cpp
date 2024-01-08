class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            // if curr interval doesn't lie in last interval
            if(ans.size() == 0 or arr[i][0] > ans.back()[1])
                ans.push_back(arr[i]);
            else    // overlap found
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
        return ans;
    }
};