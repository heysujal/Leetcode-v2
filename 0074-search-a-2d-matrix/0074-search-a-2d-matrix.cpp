class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto &row : matrix){
            if(binary_search(row.begin(), row.end(), target))
                return 1;
        }
        return 0;
    }
};