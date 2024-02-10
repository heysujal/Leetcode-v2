class Solution {
public:
    // for every bar find the left max and right max starting from itself
    // after that min(left, right) - height[bar]
    // will be added to final answer
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        vector<int> left_max(n, 0);
        vector<int> right_max(n, 0);
        left_max[0] = height[0];
        right_max[n-1] = height[n-1];
        for(int i = 1; i < n; i++){
            left_max[i] = max(left_max[i-1], height[i]);
        }
        for(int j = n-2; j >= 0; j--){
            right_max[j] = max(right_max[j+1], height[j]);
        }
        for(int i = 0; i < n; i++){
            water += min(right_max[i], left_max[i]) - height[i];
        }
        return water;
    }
};