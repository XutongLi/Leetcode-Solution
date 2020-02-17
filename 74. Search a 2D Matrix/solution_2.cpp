class Solution {
private:
    pair<bool, int> searchRow(const vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1, n = matrix[0].size();
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (matrix[m][n - 1] == target)
                return {true, m};
            else if (matrix[m][n - 1] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return {false, l};  //返回不存在及应当插入的位置
    }
    bool searchCol(const vector<vector<int>>& matrix, int target, int idx) {
        int l = 0, r = matrix[0].size() - 1;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (matrix[idx][m] == target)
                return true;
            else if (matrix[idx][m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        auto p = searchRow(matrix, target);
        if (p.first)
            return true;
        int idx = p.second;
        if (idx >= m || idx < 0)
            return false;
        return searchCol(matrix, target, idx);
    }
};
//binary search
//search row first, then search col, avoid multiply overflow
//O(logm + logn) = O(log(m*n))