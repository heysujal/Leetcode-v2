class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0;
        int end = m-1;
        int left = 0;
        int right = n-1;

        while(true){
            for(int i = left; i <= right; i++)
                ans.push_back(matrix[start][i]);
            start++;
            if(start > end)
                break;
            for(int i = start; i <= end; i++)
                ans.push_back(matrix[i][right]);
            right--;
            if(right < left)
                break;
            for(int i = right; i >= left; i--)
                ans.push_back(matrix[end][i]);
            end--;
            if(end < start)
                break;
            for(int i = end; i >= start; i--)
                ans.push_back(matrix[i][left]);
            left++;
            if(left > right)
                break;
        }
        return ans;
    }
};