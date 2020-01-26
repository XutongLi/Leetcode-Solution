class Solution {
private:
    bool isPalin(const string &s, int i, int j) {
        while (i < j) {
            if (s[i ++] != s[j --])
                return false;
        }
        return true;
    }
    void dfs(const string &s, int idx, vector<string> &cur, vector<vector<string>> &res) {
        if (idx == s.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = idx; i < s.size(); ++ i) {
            if (!isPalin(s, idx, i))
                continue;
            cur.push_back(s.substr(idx, i - idx + 1));
            dfs(s, i + 1, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.empty())
            return res;
        vector<string> cur;
        dfs(s, 0, cur, res);
        return res;
    }
};
//back tracking
//dfs