class Solution {
public:
    int n;
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)
                    q.push({i,j});
            }
        }
        int res = 0;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
            for(auto &d : dir){
                int new_x = x + d[0];
                int new_y = y + d[1];
                if(new_x >= 0 and new_y >= 0 and new_x < n and new_y < n and grid[new_x][new_y]==0){
                    q.push({new_x, new_y});
                    grid[new_x][new_y] = grid[x][y] + 1;
                    res = max(res, grid[new_x][new_y]);
                }
            }
        }
        return res - 1;
    }
};