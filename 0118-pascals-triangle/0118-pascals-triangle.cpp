class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);
        // idea is to add [i-1][j] + [i-1][j-1] of matrix
        // first and last of every row is always 1
        // every row is of i+1 length
        for(int i = 0; i < n; i++){
            ans[i] = vector<int>(i+1, 1);
            // OR ans[i].resize(i+1);
            // ans[i][0] = ans[i][i] = 1;
            for(int j = 1; j < i; j++){
                // not visiting first and last col
                ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
            }
        }
        return ans;
    }
};