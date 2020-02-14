class Solution {
public:
    string convert(string s, int n) {
        if (s.empty() || n <= 1)
            return s;
        string res("");
        int len = s.size(), dis = (2 * n - 2);
        for (int row = 1; row <= n; ++ row) {
            int idx = row - 1;
            int nei = (n - row) * 2;
            bool add_nei = (nei != dis) && (nei != 0);
            while (idx < len) {
                res += s[idx];
                if (add_nei && idx + nei < len)
                    res += s[idx + nei];
                idx += dis;
            }
        }
        return res;
    }
};
//O(n)
//找规律即可，按结果逐行从左至右添加