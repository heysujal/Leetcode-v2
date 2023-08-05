class Solution {
public:
    void rot(int i, int j, vector<vector<int>> &grid, int &fresh ,queue<pair<int,int>> &q){
        int m = grid.size();
        int n = grid[0].size();
        if(i-1 >= 0 and grid[i-1][j] == 1){
            grid[i-1][j] = 2;
            q.push({i-1,j});
            fresh--;
        }
        if(i+1 < m and grid[i+1][j] == 1){
            grid[i+1][j] = 2;
            q.push({i+1,j});
            fresh--;
        }
        if(j-1 >= 0 and grid[i][j-1]==1){
            grid[i][j-1] = 2;
            q.push({i,j-1});
            fresh--;
        }
        if(j+1 < n and grid[i][j+1] == 1){
            grid[i][j+1] = 2;
            q.push({i,j+1});
            fresh--;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int time = 0;
        queue<pair<int,int>> q;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0; j < grid[0].size() ; j++){
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        if(fresh == 0)
            return 0;
        if(fresh != 0 and q.size() == 0)
            return -1;
        while(!q.empty()){
            int size = q.size();
            time++;
            for(int t = 0; t < size ; t++){
                auto p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;
                rot(i,j,grid,fresh,q);
                if(fresh <= 0)
                    return time;
            }
        }
        if(fresh > 0)
            return -1;
    return time;
    }
};