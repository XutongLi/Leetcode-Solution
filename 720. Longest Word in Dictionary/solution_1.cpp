class Solution {
private:
    class Trie {
    public:
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
public:
    string longestWord(vector<string>& words) {
        Trie *trie = new Trie();
        for (auto w : words)
            trie->insert(w);
        string res = "";
        int len = 0;
        for (auto w : words) {
            if (w.size() < len || (w.size() == len && w >= res))
                continue;
            auto node = trie;
            bool found = true;
            for (char c : w) {
                int idx = c - 'a';
                if (!node->next[idx]->isEnd) {
                    found = false;
                    break;   
                }
                node = node->next[idx];
            }
            if (found) {
                len = w.size();
                res = w;
            }
        }
        return res;
    }
};