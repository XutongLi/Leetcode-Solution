class Trie {
public:
    Trie *next[26] = {};
    bool isEnd = false;
    string word = "";
    void insert(string &w) {
        auto node = this;
        for (auto c : w) {
            int idx = c - 'a';
            if (!node->next[idx])
                node->next[idx] = new Trie();
            node = node->next[idx];
        }
        node->isEnd = true;
        node->word = w;
    }
};

class Solution {
private:
    void dfs(vector<vector<char>>& board, Trie *trie, int i, int j, int m, int n, vector<string> &res) {
        int idx = board[i][j] - 'a';
        if (!trie->next[idx])
            return;
        trie = trie->next[idx];
        if (trie->isEnd) {
            res.push_back(trie->word);
            trie->isEnd = false;
        }
        char tmp = board[i][j];
        board[i][j] = '*';
        for (int h = -1; h <= 1; ++ h) {
            for (int v = -1; v <= 1; ++ v) {
                if (v == 0 && h == 0 || v != 0 && h != 0)
                    continue;
                int x = i + h, y = j + v;
                if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '*')
                    continue;
                dfs(board, trie, x, y, m, n, res);
            }
        }
        board[i][j] = tmp;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int m = board.size();
        if (m == 0) return res;
        int n = board[0].size();
        
        Trie *trie = new Trie();
        for (auto w : words)
            trie->insert(w);
        
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                dfs(board, trie, i, j, m, n, res);
            }
        }
        return res;
    }
};
//trie中添加每一层word，取消cur
//prefix Tree + DFS
//先根据words建立trie, DFS过程中判断前缀，不匹配时返回，提升效率