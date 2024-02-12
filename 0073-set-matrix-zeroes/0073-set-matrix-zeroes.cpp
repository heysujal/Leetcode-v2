class Solution {
public:
    // inner -> row -> col
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int col0 = 1;
        // matrix[0][...] will be used for col tracker
        // matrix[...][0] will be used for row tracker

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == 0){
                    // mark this row
                    matrix[i][0] = 0;
                    // mark this column
                    if(j == 0){
                        col0 = 0;
                    }
                    else{
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        // inner matrix first
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0)
                    continue;
                if(!matrix[0][j] or !matrix[i][0]){
                    matrix[i][j] = 0;
                }
            }
        }
        // process first row
        if(matrix[0][0] == 0){
            for(int i = 0; i < n; i++){
                matrix[0][i] = 0;
            }
        }
        // process first col
        if(col0 == 0){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};