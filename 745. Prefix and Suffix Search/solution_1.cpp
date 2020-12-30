class WordFilter {
private:
    class Trie {
    public:
        Trie *next[27] = {};
        int maxIdx = -1;
    };
    Trie *trie;
public:
    WordFilter(vector<string>& words) {
        trie = new Trie();
        for (int i = 0; i < words.size(); ++ i) {
            for (int j = 0; j <= words[i].size(); ++ j) {
                string str = words[i].substr(j) + "#" + words[i];
                auto node = trie;
                for (char c : str) {
                    int idx = (c == '#' ? 26 : c - 'a');
                    if (!node->next[idx])
                        node->next[idx] = new Trie();
                    node = node->next[idx];
                    node->maxIdx = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string str = suffix + "#" + prefix;
        auto node = trie;
        for (auto c : str) {
            int idx = (c == '#' ? 26 : c - 'a');
            if (!node->next[idx])
                return -1;
            node = node->next[idx];
        }
        return node->maxIdx;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */