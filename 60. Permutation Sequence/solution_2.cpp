class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n + 1, 1);
        vector<bool> visited(n + 1, false);
        for (int i = 1; i <= n; ++ i) {
            fact[i] = fact[i - 1] * i;
        }
        string res = "";
        for (int i = n - 1; i >= 0; -- i) {
            //确定当前k首个数字
            int num = (k % fact[i]) == 0 ? k / fact[i] : k / fact[i] + 1;   
            int cnt = 0, j;
            for (j = 1; j <= n && cnt < num; ++ j) {    //在未选择的数字钟从小到大找第num个数字
                if (!visited[j])
                    ++ cnt;
            }
            visited[-- j] = true;
            res.push_back(j + '0');
            k -= (num - 1) * fact[i];   //k减去首数字块之前的个数，如首数字为8， 减去 7 * i!
        }   
        return res;
    }
};
//time O(n ^ 2) space O(n)