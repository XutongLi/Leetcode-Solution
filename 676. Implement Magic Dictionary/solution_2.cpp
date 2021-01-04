class MagicDictionary {
private:
    vector<vector<string>> vec;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        vec.assign(101, vector<string>{});
    }
    
    void buildDict(vector<string> dictionary) {
        for (auto w : dictionary)
            vec[w.size()].push_back(w);
    }
    
    bool search(string searchWord) {
        for (auto w : vec[searchWord.size()]) {
            int cnt = 0;
            for (int i = 0; i < searchWord.size() && cnt < 2; ++ i) {
                if (w[i] != searchWord[i])  ++ cnt;
            }
            if (cnt == 1)   return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

// map O(NL)