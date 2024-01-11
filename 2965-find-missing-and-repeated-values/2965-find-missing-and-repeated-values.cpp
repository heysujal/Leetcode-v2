class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> arr;
        for(auto &row : grid)
            for(auto &val : row)
                arr.push_back(val);
        
        int i = 0;
        int n = grid.size();
        n = n*n;
        
        while(i < n){
            if(arr[i]-1 >= 0 and arr[i]-1 < n and arr[i] != arr[arr[i]-1])
                swap(arr[i], arr[arr[i]-1]);
            else
                i++;
        }

        for(int i = 0; i < n; i++)
            if(arr[i] != i + 1)
                return {arr[i], i+1};

        return {};
    }
};