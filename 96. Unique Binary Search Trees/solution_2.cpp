class Solution {
public:
    int numTrees(int n) {
        vector<int> vec(n + 1);
        vec[0] = 0;
        vec[1] = 1;
        for (int i = 2; i <= n; ++ i) {
            vec[i] = 2 * vec[i - 1];
            for (int j = 1; j <= i - 2; ++ j)
                vec[i] += vec[j] * vec[i - 1 - j];
        }
        return vec[n];
    }
};  //solution_1非递归