class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int num = 1, top = 0, bottom = n - 1, left = 0, right = n - 1;
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; ++ j)
                res[top][j] = num ++;
            for (int i = top + 1; i <= bottom; ++ i)
                res[i][right] = num ++;
            for (int j = right - 1; top < bottom && j >= left; -- j)
                res[bottom][j] = num ++;
            for (int i = bottom - 1; left < right && i > top; -- i)
                res[i][left] = num ++;
            ++ top;     -- bottom;
            ++ left;    -- right;
        }
        return res;
    }
};