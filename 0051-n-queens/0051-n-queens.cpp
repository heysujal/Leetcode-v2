class Solution {
public:

    bool isSafe(int i, int j, vector<string> &board){
        int row = i;
        while(row >= 0){
            if(board[row][j] == 'Q'){
                return false;
            }
            row--;
        }

        // upper left diagonal
        row = i;
        int col = j;

        while(row >= 0 and col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }
        
        // upper right diagonal
        row = i;
        col = j;
        while(row >= 0 and col < board[0].size()){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col++;
        }
        return true;
    }

    void helper(int i, vector<string> &board, vector<vector<string>> &ans){
        // all rows are filled
        if(i == board.size()){
            ans.push_back(board);
            return;
        }

        // start placing Q in diff columns
        for(int j = 0; j < board[0].size(); j++){
            if(isSafe(i, j, board)){
                board[i][j] = 'Q'; // place the Queen
                helper(i+1, board, ans);
                board[i][j] = '.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        helper(0, board, ans);
        return ans;
    }
};