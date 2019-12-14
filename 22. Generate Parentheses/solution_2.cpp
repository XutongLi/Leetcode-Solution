class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesis(n, res, 0, 0, "");
        return res;
    }
    void generateParenthesis(int n, vector<string> &res, int left, int right, string cur) {
        if (cur.size() == n * 2) {
            res.push_back(cur);
            return;
        }
        if (left < n)
            generateParenthesis(n, res, left + 1, right, cur + '(');
        if (right < left)
            generateParenthesis(n, res, left, right + 1, cur + ')');
    }
};