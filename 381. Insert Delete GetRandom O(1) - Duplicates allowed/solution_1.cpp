class RandomizedCollection {
private:
    vector<int> vec = {};
    unordered_map<int, unordered_set<int>> mp;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {  //O(1)
        mp[val].insert(vec.size());
        vec.push_back(val);
        return mp[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {  //O(1)
        if (mp[val].empty())
            return false;
        int i = *(mp[val].begin());
        mp[val].erase(mp[val].begin());
        vec[i] = vec.back();
        mp[vec.back()].insert(i);
        mp[vec.back()].erase(vec.size() - 1);
        vec.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {   //O(1)
        return vec[rand() % vec.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */