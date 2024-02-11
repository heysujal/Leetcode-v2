class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int helperTab(vector<vector<int>> &grid){
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
        // last row is the base case
        for(int j1 = 0; j1 < n; j1++){
            for(int j2 = 0; j2 < n; j2++){
                if(j1 == j2){
                    dp[m-1][j1][j2] = grid[m-1][j1];
                }
                else{
                    dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
                }
            }
        }

        for(int i = m-2; i >= 0; i--){
            for(int j1 = 0; j1 < n; j1++){
                for(int j2 = 0; j2 < n; j2++){
                    int sum = 0;
                    if(j1 == j2){
                        sum = grid[i][j1];
                    }
                    else{
                        sum = grid[i][j1] + grid[i][j2];
                    }
                    int ans = -1e9;
                    for(auto &d : dir){
                        int copy = sum;
                        int x = j1 + d[0];
                        int y = j2 + d[1];
                        if(x < n and x >= 0 and y < n and y >= 0){
                            copy += dp[i+1][x][y];
                        }
                        else{
                            copy = -1e9;
                        }
                        ans = max(ans, copy);
                    }
                    dp[i][j1][j2] = ans;
                }
            }
        }
        return dp[0][0][0];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        // return helper(0, 0, n-1, grid, dp);
        return helperTab(grid)+1;
    }
};