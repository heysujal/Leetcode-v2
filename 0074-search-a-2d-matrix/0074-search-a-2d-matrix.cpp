class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(m == 0 or n == 0)
            return false;
        int i = 0;
        int j = n-1;
        // bs on matrix
        while(i < m and j >= 0){
            if(matrix[i][j] > target){
                j--;
            }
            else if(matrix[i][j] < target){
                i++;
            }
            else{
                return true;
            }
        }
        return 0;
    }
};