class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) 
            return res;
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; ++ j) 
                res.push_back(matrix[top][j]);
            for (int i = top + 1; i <= bottom; ++ i) 
                res.push_back(matrix[i][right]);
            for (int j = right - 1; top < bottom && j >= left; -- j) 
                res.push_back(matrix[bottom][j]);
            for (int i = bottom - 1; left < right && i > top; -- i) 
                res.push_back(matrix[i][left]);
            ++ top;     -- bottom;
            ++ left;    -- right;
        }
        return res;
    }
};