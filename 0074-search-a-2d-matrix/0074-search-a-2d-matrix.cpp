class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0;
        int high = m*n - 1; // treat as 1D array
        while(low <= high){
            int mid = (low) + (high - low)/2;
            int ele = mat[mid/n][mid%n];
            if(ele > target){
                high--;
            }
            else if(ele < target){
                low++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};