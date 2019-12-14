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
        res.push_back("");
        for (auto dig : digits) {
            int len = m[dig - '0'].size();
            int res_len = res.size();
            for (int i = 0; i < len - 1; ++ i) {
                for (int j = 0; j < res_len;  ++ j) {
                    res.push_back(res[j] + m[dig - '0'][i]);
                }
            }
            char last = m[dig - '0'][len - 1];
            for (int i = 0; i < res_len; ++ i) {
                res[i] += last;
            }
        }
        return res;
    }
};