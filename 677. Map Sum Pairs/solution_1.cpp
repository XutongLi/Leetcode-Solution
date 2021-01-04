class MapSum {
private:
    struct Trie {
        Trie *next[26] = {};
        int val = 0;
    };
    Trie *trie;
    unordered_map<string, int> mp;
public:
    /** Initialize your data structure here. */
    MapSum() {
        trie = new Trie();
    }
    
    void insert(string key, int val) {
        int num = mp[key];
        auto node = trie;
        for (char c : key) {
            int idx = c - 'a';
            if (!node->next[idx])
                node->next[idx] = new Trie();
            node = node->next[idx];
            node->val -= num;
            node->val += val;
        }
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int res = 0;
        auto node = trie;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->next[idx])
                return 0;
            node= node->next[idx];
        }
        return node->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */