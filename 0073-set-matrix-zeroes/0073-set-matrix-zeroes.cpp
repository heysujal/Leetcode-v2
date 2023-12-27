class Solution {
public:
    // brute
    // we mark 1's as -1 and then later mark them as 0
    int m;
    int n;
    int flag = -1e9;
    void markRow(vector<vector<int>>& matrix, int row){
        for(int i = 0; i < n; i++)
            if(matrix[row][i] != 0)
                matrix[row][i] = flag;
    }
    void markCol(vector<vector<int>>& matrix, int col){
        for(int i = 0; i < m; i++)
            if(matrix[i][col] != 0)
                matrix[i][col] = flag;
    }


    void setZeroes(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    markRow(matrix, i);
                    markCol(matrix, j);
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == flag){
                    matrix[i][j] = 0;
                }
            }
        }
        return;
    }
};