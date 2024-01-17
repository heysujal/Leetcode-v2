class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq; 
        unordered_set<int> st; 
        for(auto &x : arr){
            freq[x]++;
        }

        for(auto &p : freq){
            if(st.find(p.second) != st.end())
                return false;
            st.insert(p.second);
        }
        return true;
    }
};