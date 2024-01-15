class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> winners;
        set<int> loosers;
        unordered_map<int, int> loss;
        for(auto &match : matches){
            loss[match[1]]++;
        }
        for(auto &match : matches){
            if(loss[match[0]] == 0)
                winners.insert(match[0]);
            if(loss[match[1]] == 1)
                loosers.insert(match[1]);
        }
        vector<int> v1(winners.begin(), winners.end());
        vector<int> v2(loosers.begin(), loosers.end());
        return {v1, v2};
    }
};