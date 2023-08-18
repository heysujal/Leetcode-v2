class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int mid = n/2;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += mat[i][i];  //left diagonal
            sum += mat[i][n-i-1];  // right diagonal
        }
        if(n%2 != 0) // odd
            sum -= mat[mid][mid];
        return sum;
    }
};