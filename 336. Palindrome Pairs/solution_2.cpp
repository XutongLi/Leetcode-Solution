class Solution {
private:
    bool isP(string &s, int l, int r) {
        while (l < r) {
            if (s[l ++] != s[r --])
                return false;
        }
        return true;
    }
    struct Trie {
        vector<Trie*> next;
        int idx;                //idx表示当前节点是第idx个string的结束
        vector<int> prefix;     //prefix用于处理s比trie中路径短的情况
        Trie() {
            next.assign(26, nullptr);
            idx = -1;
        }
    };
    void buildTree(Trie *trie, string &s, int idx) {  //O(k^2)
        auto node = trie;
        for (int j = s.size() - 1; j >= 0; -- j) {
            if (isP(s, 0, j))
                node->prefix.push_back(idx);    //若s后边部分isP，将此s的idx加入到本节点prefix中
            if (!node->next[s[j] - 'a'])
                node->next[s[j] - 'a'] = new Trie();
            node = node->next[s[j] - 'a'];
        }
        node->prefix.push_back(idx);    //后边部分为空，也算isP
        node->idx = idx;   
    }
    void match(Trie *trie, string &s, int idx, vector<vector<int>> &res) {  //O(k^2)
        auto node = trie;
        for (int j = 0; j < s.size(); ++ j) {
            if (node->idx != -1 && node->idx != idx && isP(s, j, s.size() - 1)) //匹配完一个trie中的string，便判断能否组成回文串
                res.push_back(vector<int>{idx, node->idx});
            node = node->next[s[j] - 'a'];
            if (!node)  return;
        }
        for (int j : node->prefix) {    //针对trie中路径比s长的情况
            if (j != idx)
                res.push_back(vector<int>{idx, j});
        }
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        Trie *trie = new Trie();
        for (int i = 0; i < words.size(); ++ i)
            buildTree(trie, words[i], i);
        for (int i = 0; i < words.size(); ++ i)
            match(trie, words[i], i, res);
        return res;
    }
};
//trie  timeO(n*k^2)
//与two trie方法的优化处为：使用每个节点的prefix数组解决trie中路径比s长的情况