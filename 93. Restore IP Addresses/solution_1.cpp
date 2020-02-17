class Solution {
private:
    void dfs(int idx, int cnt, const string &s, string &cur, vector<string> &res) {
        if (idx >= s.size() || s.size() - idx > (4 - cnt) * 3) //idx到末尾 或 s剩下长度超出最大ip长度
            return;
        int num = 0;
        bool start0 = false;
        for (int i = idx; i < idx + 3 && !start0; ++ i) {
            if (i == idx && s[i] == '0') {  //以0开始，则此部分只能为0 如1.01.1.1非法
                start0 = true;
            }
            num = num * 10 + s[i] - '0';
            if (num > 255)
                break;
            if (cnt + 1 == 4 && i == s.size() - 1) {    //四部分组成且使用所有数字
                res.push_back(cur + to_string(num));
                return;
            }
            string tmp = cur;
            cur += to_string(num) + ".";
            dfs(i + 1, cnt + 1, s, cur, res);
            cur = tmp;
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.empty() || s.size() > 12)    
            return res;
        string cur;
        dfs(0, 0, s, cur, res);
        return res;
    }
};
//backtracking