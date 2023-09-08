class Solution {
public:
    int m;
    int n;
    bool isValid(int i, int j){
        return !(i >= m or i < 0 or j < 0 or j >= n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int x, int y, int newColor) {
        m = image.size();
        n = image[0].size();
        int oldColor = image[x][y];
        if(oldColor == newColor) return image;
        image[x][y] = newColor;
        queue<pair<int,int>> q;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        q.push({x,y});
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            for(auto &d : dir){
                int i = front.first + d[0];
                int j = front.second + d[1];
                if(isValid(i,j) and image[i][j] == oldColor){
                    image[i][j] = newColor;
                    q.push({i,j});
                }
            }
        }
        return image;
    }
};