class Trie {
public:
    Trie *next[26] = {};
    //string word;
    bool isEnd = false;
    Trie() {}
    void insert(string s) {
        Trie *node = this;
        for (char c : s) {
            int idx = c - 'a';
            if (!node->next[idx])
                node->next[idx] = new Trie();
            node = node->next[idx];
        }
        //node->word = s;
        node->isEnd = true;
    }
};
class Solution {
private:
    void find(vector<vector<char>> &board, int i, int j, Trie *trie, string &cur, vector<string> &res) {
        char c = board[i][j] - 'a';
        if (!trie->next[c])
            return;
        cur.insert(cur.end(), board[i][j]);
        trie = trie->next[c];
        if (trie->isEnd) {
            res.push_back(cur);
            trie->isEnd = false;       //防止重复
        }
        char tmp = board[i][j];
        board[i][j] = '*';
        for (int h = -1; h <= 1; ++ h) {
            for (int v = -1; v <= 1; ++ v) {
                if (h != 0 && v != 0)
                    continue;
                int x = i + h, y = j + v;
                if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == '*')
                    continue;
                Trie *node = trie;
                find(board, x, y, trie, cur, res);
                trie = node;
            }
        }
        cur.pop_back();
        board[i][j] = tmp;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.empty() || words.empty())
            return res;
        Trie *trie = new Trie();
        for (auto w : words)
            trie->insert(w);
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                string cur = "";
                find(board, i, j, trie, cur, res);
            }
        }
        delete trie;
        trie = nullptr;
        return res;
    }
};
//prefix Tree + DFS
//先根据words建立trie, DFS过程中判断前缀，不匹配时返回，提升效率