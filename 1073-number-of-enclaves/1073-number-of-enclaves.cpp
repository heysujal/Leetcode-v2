class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // Push Boundary 1's in the queue
                if(i==0 || j == 0 || i == m-1 || j == n-1){
                  if(grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j] = 1;
                  }
                }
            }
        }
        int delRow[4] = {-1,0,1,0};
        int delCol[4] = {0,1,0,-1};
        // Elements that are connected to 1 will not be part of our answer
        while(q.size()!=0){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row+delRow[i];
                int ncol = col + delCol[i];
                if(nrow >=0 && nrow < m && ncol >=0 && ncol<n && grid[nrow][ncol] ==1 && visited[nrow][ncol] == 0 ){
                    q.push({nrow,ncol});
                    visited[nrow][ncol] = 1;
                }
            }
            
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && visited[i][j]==0) count++;
            }
        }
        return count;
    }
};