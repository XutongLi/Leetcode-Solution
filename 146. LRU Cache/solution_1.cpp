class LRUCache {
private:
    typedef pair<int, list<int>::iterator> val_iter;
    unordered_map<int, val_iter> cache;     //key : <value, lst iter>
    list<int> used;      //key
    int m_capacity;
    
    void touch(unordered_map<int, val_iter>::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
public:
    LRUCache(int capacity) : m_capacity(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;
        touch(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end())
            touch(it);
        else {
            if (m_capacity == cache.size()) {
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        cache[key] = {value, used.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */