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
    void dfs(Trie *node, string &res, string cur, int idx) {
        if (!node->isEnd)   return;
        cur += (char)(idx + 'a');
        if (cur.size() > res.size())
            res = cur;
        for (int i = 0; i < 26; ++ i)
            if (node->next[i])
                dfs(node->next[i], res, cur, i);
        cur = cur.substr(0, cur.size() - 1);
    }
public:
    string longestWord(vector<string>& words) {
        Trie *trie = new Trie();
        for (auto w : words)
            trie->insert(w);
        string res = "";
        int len = 0;
        for (int i = 0; i < 26; ++ i)
            if (trie->next[i])
                dfs(trie->next[i], res, "", i);
        return res;
    }
};
// Trie + DFS