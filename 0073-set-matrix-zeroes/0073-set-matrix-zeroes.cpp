class Solution {
public:
    // striver's better approach
    // we use two seperate markers in which we mark true when a zero
    // is found => mark ith row in rowtracker and jth col in colTracker
    // now reiterate matrix and make a cell zero if it is marked in both
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rowTracker(m, 0); 
        vector<int> colTracker(n, 0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    rowTracker[i] = 1;
                    colTracker[j] = 1;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rowTracker[i] or colTracker[j]){
                    matrix[i][j] = 0;
                }
            }
        }
        return;
    }
};