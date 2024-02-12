class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        unordered_map<int, int> mp;
        for(auto &c : s){
            mp[c-'a']++;
        }
        set<int> st;
        int ops = 0;
        for(auto &p : mp){
            while(st.find(p.second) != st.end()){
                ops++;
                p.second--;
                if(p.second == 0){
                    break;
                }
            }
            if(p.second != 0){
                st.insert(p.second);
            }
        }
        return ops;
    }
};