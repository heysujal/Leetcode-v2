class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        if(n==1)
            return arr;
        vector<vector<int>> ans;
        int start = arr[0][0];
        int end = arr[0][1];
        for(int i = 0; i < n; i++){
            if(arr[i][0] <= end){
                end = max(end, arr[i][1]);
            }
            else{
                ans.push_back({start, end});
                start = arr[i][0];
                end = arr[i][1];
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};