class Solution {
private:
    vector<int> mp = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};
    void dfs(int idx, int h, int m, int num, vector<string> &res) {
        if (num == 0) {
            res.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
            return;
        }
        for (int i = idx; i < 10; ++ i) {
            if (i < 4) {
                if (h + mp[i] < 12)
                    dfs(i + 1, h + mp[i], m, num - 1, res);
            }
            else {
                if (m + mp[i] < 60)
                    dfs(i + 1, h, m + mp[i], num - 1, res);
            }
        }
    }
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        dfs(0, 0, 0, num, res);
        return res;
    }
};