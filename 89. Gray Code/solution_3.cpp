class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};
        for (int i = 0; i < n; ++ i) {
            int plus = 1 << i;
            for (int j = res.size() - 1; j >= 0; -- j) {
                res.push_back(res[j] + plus);
            }
        }
        return res;
    }
};
// 0 0 0 -- n
//-------
// 0 0 1 -- 0
// -----
// 0 1 1
// 0 1 0 -- 1
// ------
// 1 1 0
// 1 1 1
// 1 0 1
// 1 0 0 -- 2