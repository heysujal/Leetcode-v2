class Solution {
public:
    int m;
    int n;
    int helperMemo(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(i >= m or j >= n or j < 0){
            return 1e9;
        }
        if(i == m-1 and (j >=0 and j < n)){
            return matrix[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int op1 = helperMemo(i+1, j-1, matrix, dp);
        int op2 = helperMemo(i+1, j+1, matrix, dp);
        int op3 = helperMemo(i+1, j, matrix, dp);
        int ans = matrix[i][j] + min(op1, min(op2, op3));
        return dp[i][j] = ans;
    }
    int helperTab(vector<vector<int>> &matrix){
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // last row is my base case to start with
        for(int j = 0; j < n; j++){
            dp[m-1][j] = matrix[m-1][j];
        }
        // try falling path from down to top row
        for(int i = m-2; i >= 0; i--){ // i+1 is always valid
            for(int j = 0; j < n; j++){ // j+1 and j-1 need to be handled
                int op1 = 1e9;
                int op2 = 1e9;
                int op3 = 1e9;
                op1 = dp[i+1][j];
                if(j != 0)
                    op2 = dp[i+1][j-1];

                if(j != n-1)
                    op3 = dp[i+1][j+1];
                dp[i][j] = matrix[i][j] + min(op1, min(op2, op3));
            }
        }
        int ans = 1e9;
        // getting answer from the first row
        for(int col = 0; col < n; col++)
            ans = min(ans, dp[0][col]);
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        // Memo stars
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // dp[i][j] represents min falling path sum starting from 
        // [i][j] to (m-1)th row i.e. last row
        // int ans = INT_MAX;
        // for(int j = 0; j < n; j++){
        //     ans = min(ans, helperMemo(0, j, matrix, dp));
        // }
        // return ans;
        // Memo done
        return helperTab(matrix);
    }
};