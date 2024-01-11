class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        n = n*n;
        //assumption x => repeating, y is missing
        // S-Sn = x - y
        // S2 - Sn2 = x2 - y2
        long long S = 0, S2 = 0;
        for(auto &row : grid){
            for(auto &val : row){
                S += (long long)val;
                S2 += (long long)val * (long long)val;
            }
        }
        long long Sn = (n * (n+1))/2;
        long long Sn2 = (n * (n+1) * (2*n+1))/6;
        long long val1 = S - Sn; // x- y
        long long val2 = S2 - Sn2; // x2 - y2
        long long val3 = val2 / val1; // x + y
        long long  x = (val3 + val1)/2; // x 
        long long  y = val3 - x;
        return {(int)x, (int)y};
    }
};