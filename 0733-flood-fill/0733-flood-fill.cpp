class Solution {
public:
    
    int m = 0;
    int n = 0;
    void dfs(int i, int j, int oldColor, int newColor, vector<vector<int>> &image){
        if(i < 0 or j < 0 or i >= m or j >= n or image[i][j] != oldColor)
            return;
        image[i][j] = newColor;
        dfs(i-1,j,oldColor,newColor,image);
        dfs(i,j-1,oldColor,newColor,image);
        dfs(i+1,j,oldColor,newColor,image);
        dfs(i,j+1,oldColor,newColor,image);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int x, int y, int newColor) {
        m = image.size();
        n = image[0].size();
        int oldColor = image[x][y];
        if(oldColor == newColor) return image;
        dfs(x,y,oldColor,newColor,image);
        return image; 
    }
};