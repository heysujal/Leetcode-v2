class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    bool isValid(int i, int j){
        return !(i >= m or i < 0 or j < 0 or j >= n);
    }
    void dfs(int i, int j, int &area, vector<vector<bool>> &vis, vector<vector<int>> &grid){
        if(!isValid(i,j) or grid[i][j] != 1 or vis[i][j] == true)
            return;
        area++; 
        vis[i][j] = true;
        for(auto &d : dir){
            int x = i + d[0];
            int y = j + d[1];
            dfs(x,y,area,vis,grid);
        }  
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int area = 0;
                dfs(i,j,area,vis,grid);
                ans = max(area, ans);
            }
        }
        return ans;
    }
};