class WordDictionary {
private:
    class TrieNode {
    public:
        TrieNode *next[26] = {};
        bool isWord = false;
        TrieNode() {}
    };
TrieNode *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *node = root;
        for (auto c : word) {
            if (!node->next[c - 'a'])
                node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, root, 0);
    }
    
    bool search(const string &word, TrieNode *cur, int idx) {
        if (idx == word.size())
            return cur->isWord;
        if (word[idx] != '.') {
            if (!cur->next[word[idx] - 'a'])
                return false;
            return search(word, cur->next[word[idx] - 'a'], idx + 1);
        }
        else {
            for (int i = 0; i < 26; ++ i) {
                if (!cur->next[i])
                    continue;
                if (search(word, cur->next[i], idx + 1))
                    return true;
            }
        }
        return false;
    }
};
//Trie
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */