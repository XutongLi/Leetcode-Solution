class Solution {
public:
    int numTrees(int n) {
        vector<int> vec(n + 1);
        vec[0] = 1;
        vec[1] = 1;
        for (int i = 2; i <= n; ++ i) {
            for (int j = 1; j <= i; ++ j)
                vec[i] += vec[j - 1] * vec[i - j];
        }
        return vec[n];
    }
}; 
//g(i) 表示序列长度为i的树个数
//f(j, i) 表示序列长度为i， 以第j个节点作为根的树的个数
//g(i) = sum_(j = 1)^(i)f(j, i)
//f(j, i) = g(j - 1)*g(i - j)
//所以 g(i) = sum_(j = 1)^(i)g(j - 1)*g(i - j)