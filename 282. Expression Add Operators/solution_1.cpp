class Solution {
private:
    //sum为当前总值，opval为上一个操作数，cur为当前string
    void dfs(const string &num, int idx, long long sum, long long opval, string cur, int target, vector<string> &res) {
        if (idx == num.size() && sum == target) {
            res.push_back(cur);
            return;
        }
        for (int len = 1; idx + len <= num.size(); ++ len) {
            if (len > 1 && num[idx] == '0')     //以0开头，则val只能为0
                break;
            string str = num.substr(idx, len);
            long long val = stoll(str);
            if (idx == 0) 
                dfs(num, idx + len, val, val, str, target, res);
            else {
                dfs(num, idx + len, sum + val, val, cur + "+" + str, target, res);
                dfs(num, idx + len, sum - val, -val, cur + "-" + str, target, res);
                dfs(num, idx + len, sum - opval + opval * val, opval * val, cur + "*" + str, target, res);
                //如1+2*3 ,4 (opval=6) -> 1+2*3*4 (opval=24) 
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num, 0, 0, 0, "", target, res);
        return res;
    }
};
//dfs solution