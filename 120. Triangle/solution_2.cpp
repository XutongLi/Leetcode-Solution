class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty())
            return 0;
        int n = triangle.size();
        vector<int> res(n + 1, 0);
        for (int i = n - 1; i >= 0; -- i) {
            for (int j = 0; j < triangle[i].size(); ++ j) {
                res[j] = min(res[j], res[j + 1]) + triangle[i][j];
            }
        }
        return res[0];
    }
};
//time O(n) n is all num of elements  
//space O(n)
//does not modify resource array