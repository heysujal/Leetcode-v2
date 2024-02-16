class Solution {
public:
    class cmp{
        public:
            bool operator()(pair<int, int> p1, pair<int, int> p2){
                return p1.second > p2.second;
            }
    };
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto &x : arr){
            mp[x]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(auto &p : mp){
            pq.push(p);
        }
        while(k--){
            if(pq.top().second == 1){
                pq.pop();
            }
            else{
                auto t = pq.top();
                pq.pop();
                pq.push({t.first, t.second-1});
            }
        }
        return pq.size();
    }
};