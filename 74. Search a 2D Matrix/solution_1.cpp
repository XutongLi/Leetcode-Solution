class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        int m = matrix.size(), n = matrix[0].size(), l = 0, r = n * (m - 1) + n - 1;
        while (l <= r) {
            int mid = (r - l) / 2 + l, num = matrix[mid / n][mid % n];
            if (num == target)
                return true;
            else if (num > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};
//binary search
//O(log(mn))