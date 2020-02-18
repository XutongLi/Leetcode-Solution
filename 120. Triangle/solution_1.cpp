class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty())
            return 0;
        int n = triangle.size();
        if (n == 1)
            return triangle[0][0];
        for (int i = 1; i < n; ++ i) {
            int len = triangle[i].size();
            triangle[i][0] += triangle[i - 1][0];
            for (int j = 1; j <= len - 2; ++ j) {
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
            triangle[i][len - 1] += triangle[i - 1][len - 2];
        }
        int mini = INT_MAX;
        for (auto e : triangle[n - 1])
            mini = min(mini, e);
        return mini;
    }
};
//time O(n) n is all num of elements  
//space O(1)