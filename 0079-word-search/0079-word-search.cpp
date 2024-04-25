class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool helper(int i, int j, string word, vector<vector<char>> &board){
        if(word.size() == 0){
            return true;
        }
        if(i < 0 or j < 0 or i >= m or j >= n){
            return false;
        }
        if(board[i][j] == word[0]){
            auto t = board[i][j];
            board[i][j] = '?';
            for(auto &d : dir){
                int x = i + d[0];
                int y = j + d[1];
                if(helper(x, y, word.substr(1), board)){
                    return true;
                }
            }
            board[i][j] = t;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; ++j){
                if(helper(i, j, word, board)){
                    return true;
                }
            }
        }
        return false;
    }
};