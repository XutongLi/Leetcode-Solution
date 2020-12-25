class Trie {
public:
    Trie *next[26] = {};
    bool isEnd = false;
    void insert(string &w) {
        auto node = this;
        for (auto c : w) {
            int idx = c - 'a';
            if (!node->next[idx])
                node->next[idx] = new Trie();
            node = node->next[idx];
        }
        node->isEnd = true;
    }
};
class Solution {
private:
    int find(Trie *trie, string &w, int index, int count) {
        auto node = trie;
        for (int i = index; i < w.size(); ++ i) {
            int idx = w[i] - 'a';
            if (!node->next[idx])
                return false;
            node = node->next[idx];
            if (node->isEnd) {
                if (i == w.size() - 1)
                    return count >= 1;
                if (find(trie, w, i + 1, count + 1))
                    return true;
            }
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        int n = words.size();
        if (n == 0) return res;

        Trie *trie = new Trie();
        for (int i = 0; i < n; ++ i) {
            if (words[i].size() == 0)
                continue;
            trie->insert(words[i]);
        }

        for (int i = 0; i < n; ++ i) {
            if (words[i].size() == 0)
                continue;
            if (find(trie, words[i], 0, 0))
                res.push_back(words[i]);
        }
        return res;
    }
};