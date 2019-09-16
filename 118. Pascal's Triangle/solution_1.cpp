class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows <= 0)
            return res;
        for (int row = 1; row <= numRows; row ++) {
            vector<int> tmp;
            tmp.push_back(1);
            if (row == 1) {
                res.push_back(tmp);
                continue;
            }    
            for (int i = 1; i < row; i ++) {
                if (i == res[row - 2].size())
                    tmp.push_back(1);
                else
                    tmp.push_back(res[row - 2][i] + res[row - 2][i - 1]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};