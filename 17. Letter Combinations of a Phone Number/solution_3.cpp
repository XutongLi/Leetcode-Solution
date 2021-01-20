class Solution {
private:
    unordered_map<int, string> m;
    void map_insert() {
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
    }
    void dfs(string &digits, vector<string> &res, string &cur, int idx) {
        if (idx == digits.size()) {
            res.push_back(cur);
            return;
        }
        for (char c : m[digits[idx] - '0']) {
            cur += c;
            dfs(digits, res, cur, idx + 1);
            cur.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        map_insert();
        vector<string> res;
        if (digits.empty())
            return res;
        string cur = "";
        dfs(digits, res, cur, 0);
        return res;
    }
};