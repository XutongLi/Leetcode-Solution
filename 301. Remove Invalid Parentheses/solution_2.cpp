class Solution {
private:
    bool isValid(const string &s) {
        int sum = 0;
        for (auto c : s) {
            if (c == '(')
                ++ sum;
            else if (c == ')') 
                -- sum;
            if (sum < 0)
                return false;
        }
        return sum == 0;
    }
    void helper(string s, int beg, int left, int right, vector<string> &res) {
        if (left == 0 && right == 0) {  //s为空时也满足此条件
            if (isValid(s))
                res.push_back(s);
            return;
        }
        for (int i = beg; i < s.size(); ++ i) {
            string tmp = s;
            if (left > 0 && tmp[i] == '(') {
                if (i == beg || tmp[i] != tmp[i - 1]) { //防止重复
                    tmp.erase(i, 1);
                    helper(tmp, i, left - 1, right, res);
                }
            }
            if (right > 0 && tmp[i] == ')') {
                if (i == beg || tmp[i] != tmp[i - 1]) {
                    tmp.erase(i, 1);
                    helper(tmp, i, left, right - 1, res);
                }
            }
        }
        
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int left = 0, right = 0;
        for (auto c : s) {
            if (c == '(')
                ++ left;
            else if (c == ')') {
                if (left == 0)
                    ++ right;
                else
                    -- left;
            }
        }
        helper(s, 0, left, right, res);
        return res;
    }
};
//depth limited DFS