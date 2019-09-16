class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if (rowIndex < 0)
            return res;
        while (rowIndex -- >= 0) {
            res.insert(res.begin(), 1);
            for (int i = 1; i < res.size() - 1; i ++) {
                res[i] += res[i + 1];
            }
        }
        return res;
    }
};