class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dir  = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool helper(int i, int j, int k, vector<vector<char>>& board, string word){
        if(k == word.size()){
            return true;
        }
        if(i >= m or j >= n or i < 0 or j < 0 or board[i][j] != word[k]){
            return false;
        }
        char ch = board[i][j];
        board[i][j] = '?';
        for(auto &d : dir){
            int x = i + d[0];
            int y = j + d[1];
            if(helper(x, y, k+1, board, word)){
                return true;
            }
        }
        board[i][j] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(helper(i, j, 0, board, word)){
                    return true;
                }
            }
        }
        return false;
    }
};