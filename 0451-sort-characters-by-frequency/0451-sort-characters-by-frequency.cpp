class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp;

        for(auto &ch : s){
            mp[ch]++;
        }

        for(auto &p : mp){
            pq.push({p.second, p.first}); // adding freq as key and char as value
        }

        string ans = "";
        while(!pq.empty()){
            auto top = pq.top();
            auto freq = top.first;
            auto ch = top.second;
            pq.pop();
            while(freq--){
                ans.push_back(ch);
            }
        }
        return ans;
    }
};