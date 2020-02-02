class RandomizedSet {
private:
    vector<int> vec;
    unordered_map<int, int> mp;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
        vec = {};
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.find(val) == mp.end()) {
            vec.push_back(val);
            mp[val] = vec.size() - 1;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mp.find(val) == mp.end())
            return false;
        int idx = mp[val];
        swap(vec[idx], vec[vec.size() - 1]);
        mp[vec[idx]] = idx;
        mp.erase(vec[vec.size() - 1]);
        vec.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand() % static_cast<int>(vec.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */