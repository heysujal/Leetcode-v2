class Solution {
public:
    void helper(int i, vector<string> &board, vector<vector<string>> &ans, vector<int> &col, vector<int> &left_diag, vector<int> &right_diag){
        int n = board.size();
        // all rows are filled
        if(i == board.size()){
            ans.push_back(board);
            return;
        }

        // start placing Q in diff columns
        for(int j = 0; j < board[0].size(); j++){
            if(col[j] == 0 and left_diag[n-1 + i-j] == 0 and right_diag[i+j] == 0){
                left_diag[n-1 + i-j] = 1;
                right_diag[i+j] = 1;
                board[i][j] = 'Q'; // place the Queen
                helper(i+1, board, ans);
                board[i][j] = '.';
                left_diag[n-1 + i-j] = 0;
                right_diag[i+j] = 0;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> col(n, 0);
        vector<int> left_diag(2*n, 0);
        vector<int> right_diag(2*n, 0);
        helper(0, board, ans, left_diag, right_diag);
        return ans;
    }
};