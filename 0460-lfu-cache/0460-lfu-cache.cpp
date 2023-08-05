class LFUCache {
public:
    int size;
    int cap;
    // key->address of list node
    unordered_map<int,list<vector<int>>::iterator> mp;
    map<int,list<vector<int>>> freqMap;
    // freq -> list<{key,value,freq},{key,value,freq},{key,value,freq}>
    // freq -> list<{key,value,freq},{key,value,freq},{key,value,freq}>
    // freq -> list<{key,value,freq},{key,value,freq},{key,value,freq}>
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    void makeRecentlyUsed(int key){
        auto &vec = *mp[key];
        int f = vec[2];
        int value = vec[1];
        freqMap[f].erase(mp[key]);
        if(freqMap[f].empty())
            freqMap.erase(f);
        f++;
        freqMap[f].push_front(vector<int>({key,value,f}));
        mp[key] = freqMap[f].begin();
    }
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        auto &vec = *mp[key];
        int val = vec[1];
        makeRecentlyUsed(key);
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            auto &vec = *mp[key];
            vec[1] = value;
            makeRecentlyUsed(key);
        }else if(size < cap){
            // insert
            size++;
            freqMap[1].push_front(vector<int>({key,value,1}));
            mp[key] = freqMap[1].begin();
        }else{
            //delete least frequent
            auto &firstList = freqMap.begin()->second;
            int delKey = (firstList.back())[0];
            firstList.pop_back();
            if(firstList.empty()) //edge case
                freqMap.erase(freqMap.begin()->first);
            freqMap[1].push_front(vector<int>({key,value,1}));
            mp.erase(delKey);
            mp[key] = freqMap[1].begin();

        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */