class Solution {
private:
    class Trie {
    private:
        Trie *next[26] = {};
        bool isEnd = false;
    public:
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
        string search(string &w) {
            string str = "";
            auto node = this;
            for (char c : w) {
                int idx = c - 'a';
                if (!node->next[idx])
                    break;
                str += c;
                node = node->next[idx];
                if (node->isEnd)
                    return str;
            }
            return w;
        }
    };
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie *trie = new Trie();
        for (string w : dictionary)
            trie->insert(w);
        stringstream ss(sentence);
        string w;
        string res = "";
        while (ss >> w) {
            res += (" " + trie->search(w));
        }
        return res.substr(1);
    }
};