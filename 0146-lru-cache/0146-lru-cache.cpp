class LRUCache {
public:
    int maxSize;
    int size;
    unordered_map<int,int> mp; // key->val
    unordered_map<int,list<int>::iterator> address; // key->iterator
    list<int> l;
    LRUCache(int capacity) {
        maxSize = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        auto it = address[key];
        l.erase(it);
        l.push_front(key);
        address.erase(key);
        address[key] = l.begin();
        return mp[key];
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            // make this recently used
            auto it = address[key];
            l.erase(it);
            address.erase(key);
            l.push_front(key);
            address[key] = l.begin();
        }else{
            // not present already
            if(size==maxSize){
                // remove last key
                int k = l.back();
                l.erase(address[k]);
                address.erase(k);
                mp.erase(k);
                size--;
            }
            size++;
            l.push_front(key);
            address[key] = l.begin();    
        }
        mp[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */