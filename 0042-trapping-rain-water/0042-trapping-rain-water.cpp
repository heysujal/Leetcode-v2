class Solution {
public:
    // for every bar find the left max and right max starting from itself
    // after that min(left, right) - height[bar]
    // will be added to final answer
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        for(int i = 0; i < n; i++){
            int left_max = height[i];
            int right_max = height[i];
            for(int t = 0; t < i; t++){
                left_max = max(left_max, height[t]);
            }
            for(int t = i+1; t < n; t++){
                right_max = max(right_max, height[t]);
            }

            water += min(left_max, right_max) - height[i];
        }
        return water;
    }
};