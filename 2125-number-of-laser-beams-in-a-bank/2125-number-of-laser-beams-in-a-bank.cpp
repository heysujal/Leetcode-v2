class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        // lasers by ith row means =>1s in i-th row * 1s in i+1 th ro/w;
        int beams = 0;
        int m = bank.size();
        int n = bank[0].size();
        vector<int> count;
        for(int i = 0; i < m; i++){
            int t = 0;
            for(int j = 0; j < n; j++){
                if(bank[i][j] == '1'){
                    t++;
                }
            }
            if(t != 0)
                count.push_back(t);
        }
        int size = count.size();
        for(int i = 0; i < size-1; i++){
            beams += (count[i] * count[i+1]);
        }
        return beams;
    }
};