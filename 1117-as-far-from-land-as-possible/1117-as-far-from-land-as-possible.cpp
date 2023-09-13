class Solution {
public:
    int n;
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        int water = 0;
        int land = 0;
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    land++;
                    q.push({{i,j},0});
                    grid[i][j] = 2;
                }
                else{
                    water++;
                }
            }
        }
        if(land == 0 or water == 0)
            return -1;
        int res = 0;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int distance = q.front().second; 
            q.pop();
            for(auto &d : dir){
                int new_x = x + d[0];
                int new_y = y + d[1];
                if(new_x >= 0 and new_y >= 0 and new_x < n and new_y < n and grid[new_x][new_y] != 2){
                    q.push({{new_x, new_y},distance+1});
                    grid[new_x][new_y] = 2;
                    res = max(res, distance+1);
                }
            }
        }
        return res;
    }
};