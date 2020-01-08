class Trie {
private:
    Trie *next[26] = {};    //指针数组
    bool isEnd = false;;
public:
    /** Initialize your data structure here. */
    Trie() {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->next[idx])
                node->next[idx] = new Trie();
            node = node->next[idx];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->next[idx])
                return false;
            node = node->next[idx];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!node->next[idx])
                return false;
            node = node->next[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */