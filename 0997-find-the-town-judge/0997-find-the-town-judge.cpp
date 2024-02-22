class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> out(n+1), in(n+1);
        for(auto &v : trust){
            out[v[0]]++;
            in[v[1]]++;
        }
        for(int i = 1; i <= n; i++){
            if(out[i] == 0 and in[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};