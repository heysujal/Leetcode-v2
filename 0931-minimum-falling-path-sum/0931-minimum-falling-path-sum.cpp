class Solution {
public:
    int m;
    int n;

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
    int helperSpace(vector<vector<int>> &matrix){
        vector<int> next(n, 1e9);
        // last row is my base case to start with
        for(int j = 0; j < n; j++){
            next[j] = matrix[m-1][j];
        }
        // try falling path from down to top row
        for(int i = m-2; i >= 0; i--){ // i+1 is always valid
            vector<int> curr(n, 1e9);
            for(int j = 0; j < n; j++){ // j+1 and j-1 need to be handled
                int op1 = 1e9;
                int op2 = 1e9;
                int op3 = 1e9;
                op1 = next[j];
                if(j != 0)
                    op2 = next[j-1];

                if(j != n-1)
                    op3 = next[j+1];
                curr[j] = matrix[i][j] + min(op1, min(op2, op3));
            }
            next = curr;
        }
        int ans = 1e9;
        // getting answer from the first row
        for(int col = 0; col < n; col++)
            ans = min(ans, next[col]);
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        return helperSpace(matrix);
    }
};