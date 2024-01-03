class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    bool helper(int i, int j, vector<vector<char>>& board, string word){
        if(word.size() == 0)
            return true;
        if(i < 0 or j >= n or i >= m or j < 0 or board[i][j]=='?')
            return false;
        if(word[0] == board[i][j]){
            auto t = board[i][j];
            board[i][j] = '?';
            for(auto &d : dir){
                if(helper(i + d[0], j + d[1], board, word.substr(1))){
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
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(helper(i, j, board, word))
                    return true;
            }
        }
        return false;
    }
};