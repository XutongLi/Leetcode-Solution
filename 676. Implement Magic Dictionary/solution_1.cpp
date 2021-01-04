class MagicDictionary {
private:
    struct Trie {
        Trie *next[26] = {};
        bool isEnd = false;
        void insert(string &w) {
            auto node = this;
            for (char c : w) {
                int idx = c - 'a';
                if (!node->next[idx])
                    node->next[idx] = new Trie();
                node = node->next[idx];
            }
            node->isEnd = true;
        }
    };
    Trie *trie;
    bool dfs(Trie *node, string &w, int index, bool diff) {
        if (index == w.size()) {
            if (node->isEnd && diff)
                return true;
            return false;
        }
        int idx = w[index] - 'a';
        if (!diff) {
            for (int i = 0; i < 26; ++ i) {
                if (i != idx && node->next[i] && dfs(node->next[i], w, index + 1, true))
                    return true;
            }
        }
        if  (node->next[idx])
            return dfs(node->next[idx], w, index + 1, diff);
        else    return false;
    }
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        trie = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for (auto w : dictionary)
            trie->insert(w);
    }
    
    bool search(string searchWord) {
        return dfs(trie, searchWord, 0, false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */