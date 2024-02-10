class Solution {
public:
    // O(1) space approach
    int trap(vector<int>& height) {
        int n = height.size();
        // Assuming left is the limiting factor!
        // what if there is a even more smaller in between left and right
        // Ans. it will be stopped by longer right bar
        int left = 0;
        int right = height.size()-1;
        int left_max = 0;
        int right_max = 0;
        int water = 0;
        while(left <= right){
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if(left_max < right_max){
                water += left_max - height[left];
                left++;
            }
            else{
                water += right_max - height[right];
                right--;
            }
        }
        return water;
    }
};