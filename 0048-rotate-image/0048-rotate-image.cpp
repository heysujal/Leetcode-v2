class Solution {
public:

    void rotate(vector<vector<int>>& matrix) {
        // Algo
        // Transpose
        // Reverse each row
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(auto &row : matrix){
            reverse(row.begin(), row.end());
        }
        return;
    }
};