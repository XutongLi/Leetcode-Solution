class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int j = 0; j < n / 2; ++ j) {
            for (int i = j; i < n - j - 1; ++ i) {
                int ti =i, tj = j, cur = matrix[ti][tj];
                int cnt = 4;
                while (cnt -- > 0) {
                    swap(cur, matrix[tj][n - ti - 1]);
                    int tmp = ti;
                    ti = tj;
                    tj = n - tmp - 1;
                }
            }
        }
    }
};
/*
1 2 3 4        1 2 3 1         1 2 3 1           13 2 3 1
5 6 7 8        5 6 7 8         5 6 7 8           5 6 7 8  
9 10 11 12     9 10 11 12      9 10 11 12        9 10 11 12
13 14 15 16    13 14 15 4      16 14 15 4        16 12 15 4

依次进行循环


*/