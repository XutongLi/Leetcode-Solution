class Solution {
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
public:
    vector<string> letterCombinations(string digits) {
        map_insert();
        vector<string> res;
        if (digits.empty())
            return res;
        letterCombinations(digits, "", 0, res);
        return res;
    }
    void letterCombinations(string digits, string now, int idx, vector<string> &res) {
        if (idx == digits.length()) {
            res.push_back(now);
            return;
        }
        string tmp = m[digits[idx] - '0'];
        for (char tmpc : tmp) {
            letterCombinations(digits, now + tmpc, idx + 1, res);  
        }
    }
};