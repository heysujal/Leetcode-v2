class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int len = INT_MIN;
        unordered_map<char, vector<int>> mp;
        int idx = 0;
        for(auto ch : s){
            mp[ch].push_back(idx);
            idx++;
        }
        bool flag = false;
        for(auto &p : mp){
            auto v = p.second;
            int size = v.size();
            if(size > 1)
                flag = true;
            int f = v[0];
            int l = v[v.size() - 1];
            len = max(len, l - f - 1);
        }
        if(!flag)
            return -1;
        return len;
    }
};