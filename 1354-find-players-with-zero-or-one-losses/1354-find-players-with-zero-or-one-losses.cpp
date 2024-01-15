class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> v1;
        vector<int> v2;
        map<int, int> loss;
        for(auto &match : matches){
            loss[match[1]]++;
            if(loss.count(match[0]) == 0)
                loss[match[0]] = 0;
        }
        for(auto &p : loss){
            if(p.second == 0)
                v1.push_back(p.first);
            if(p.second == 1)
                v2.push_back(p.first);
        }
        return {v1, v2};
    }
};