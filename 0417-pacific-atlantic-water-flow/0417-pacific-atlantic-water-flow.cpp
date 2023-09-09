class Solution {
public:
    int m = 0;
    int n = 0;
    void solve(int i, int j, int parent, vector<vector<int>>& ocean,vector<vector<int>>& heights){
        if(i < 0 or j < 0 or i >= m or j >= n)
            return;
        if(heights[i][j] < parent)
            return;
        if(ocean[i][j] == 1)
            return;
        ocean[i][j] = 1;
        solve(i-1,j,heights[i][j],ocean,heights);
        solve(i+1,j,heights[i][j],ocean,heights);
        solve(i,j+1,heights[i][j],ocean,heights);
        solve(i,j-1,heights[i][j],ocean,heights);    
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> pacific(m, vector<int>(n, 0));        
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        int prev = INT_MIN;
        // So, there should be increasing order for the flow
        // for pacific borders
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 or j == 0)
                    solve(i,j,prev,pacific,heights);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == m-1 or j == n-1)
                    solve(i,j,prev,atlantic,heights);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] == 1 and atlantic[i][j] == 1)
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};