class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < i; ++ j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};

/*
1 2 3
4 5 6
7 8 9

7 8 9
4 5 6
1 2 3

7 4 1
8 5 2
9 6 3


*/