class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size() - 1;
        int maxarea = 0 ;
        while(low < high){
            int minheight = min(height[low], height[high]);
            int width = high-low;
            int area = minheight*width;
            maxarea = max(maxarea, area);
            if(minheight==height[low])
                low++;
            else if(minheight == height[high])
                high--;
            else{
                high--;
                low++;
            }
        }
        return maxarea;
    }
};