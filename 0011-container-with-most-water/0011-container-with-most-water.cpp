class Solution {
public:
    int maxArea(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int maxarea = 0;
        while(low < high){
            int minheight = min(nums[low], nums[high]);
            int width = high - low;
            int area = minheight * width;
            maxarea = max(maxarea, area);
        // shrink from where height is lower
            if(minheight == nums[low]){
                low++;
            }
            else if(minheight == nums[high]){
                high--;
            }
        }
        return maxarea;
    }
};