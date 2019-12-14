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
        for (char dig : digits) {
            int res_len = res.size();
            for (int k = 0; k < res_len; ++ k) {
                string tmp = res[0];
                res.erase(res.begin());
                for (char item : m[dig - '0']) {
                    res.push_back(tmp + item);
                }
            }
        }
        return res;
    }
};