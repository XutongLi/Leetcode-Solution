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
        int idx;
        Trie() {
            next.assign(26, nullptr);
            idx = -1;
        }
    };
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie *trie = new Trie();
        Trie *rtrie = new Trie();
        //build trie O(nk)
        for (int j = 0; j < words.size(); ++ j) {
            string s = words[j];
            //build trie
            auto node = trie;
            for (int i = 0; i < s.size(); ++ i) {
                if (!node->next[s[i] - 'a']) 
                    node->next[s[i] - 'a'] = new Trie();
                node = node->next[s[i] - 'a'];  
            }
            node->idx = j;
            //build reversed trie
            auto rnode = rtrie;
            for (int i = s.size() - 1; i >= 0; -- i) {
                if (!rnode->next[s[i] - 'a']) 
                    rnode->next[s[i] - 'a'] = new Trie();
                rnode = rnode->next[s[i] - 'a'];
            }
            rnode->idx = j;
        }
        
        vector<vector<int>> res;
        unordered_set<string> saved;
        //match time O(nk^2)
        for (int j = 0; j < words.size(); ++ j) {
            string s = words[j];
            //match trie
            auto node = trie;
            int i = s.size() - 1;
            if (node->idx != -1 && node->idx != j && isP(s, 0, i)  && saved.find(to_string(node->idx) + "-" + to_string(j)) == saved.end()) {    //对于trie中空串情况    
                res.push_back({node->idx, j});
                saved.insert(to_string(node->idx) + "-" + to_string(j));
            }
            for (; i >= 0 && node->next[s[i] - 'a']; -- i) {
                node = node->next[s[i] - 'a'];
                if (node->idx != -1 && node->idx != j && isP(s, 0, i - 1)  && saved.find(to_string(node->idx) + "-" + to_string(j)) == saved.end()) {    
                    res.push_back({node->idx, j});
                    saved.insert(to_string(node->idx) + "-" + to_string(j));
                }
            }
            //match reversed trie
            auto rnode = rtrie;
            i = 0;
            if (rnode->idx != -1 && rnode->idx != j && isP(s, i, s.size() - 1) && saved.find(to_string(j) + "-" + to_string(rnode->idx)) == saved.end()) {  //对于rtrie中空串情况    
                res.push_back({j, rnode->idx});
                saved.insert(to_string(j) + "-" + to_string(rnode->idx));
            }
            for (; i < s.size() && rnode->next[s[i] - 'a']; ++ i) {
                rnode = rnode->next[s[i] - 'a'];
                if (rnode->idx != -1 && rnode->idx != j && isP(s, i + 1, s.size() - 1) && saved.find(to_string(j) + "-" + to_string(rnode->idx)) == saved.end()) {    
                    res.push_back({j, rnode->idx});
                    saved.insert(to_string(j) + "-" + to_string(rnode->idx));
                }
            }
        }
        return res;
    }
};
//trie time O(nk^2)
//使用两个trie是因为长度原因，reversed trie是将单词的字母倒序构建，如lls在rtrie中构建为sll
//如lls、sssll需使用trie（短的在trie中）
//llsss,sll需使用reversed trie（短的在trie中）