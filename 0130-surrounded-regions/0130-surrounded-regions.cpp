class Solution {
public:
    // Idea: 
    // Instead of finding islands that are surrounded and mark them as X
    // We actually find those who are attached to boundary
    // and they will not get Submerged/Captured by X
    int m;
    int n;
    
    void dfs(int i, int j, vector<vector<char>> &board){
        if(i >= m or j < 0 or i < 0 or j >= n or board[i][j] != 'O'){
            return;
        }
        // mark it(the cells connected to boundary)
        board[i][j] = '#';
        dfs(i, j-1, board);
        dfs(i+1, j, board);
        dfs(i-1, j, board);
        dfs(i, j+1, board);
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // traverse from boundary only
                if(i == 0 or i == m-1 or j == 0 or j == n-1){
                    dfs(i, j, board);
                }
            }
        }
        // Now all left 'O's will get captured
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                // Recovering those 'O's who didn't get Captured
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};