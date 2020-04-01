class Solution {
private:
    int dfs(const vector<int> &boxes, int mem[100][100][100], int l, int r, int k) {
        if (l > r)  return 0;
        if (mem[l][r][k] > 0)   return mem[l][r][k];
        while (r > l && boxes[r] == boxes[r - 1]) {
            -- r;   ++ k;
        }
        mem[l][r][k] = dfs(boxes, mem, l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = l; i < r; ++ i) {
            if (boxes[i] == boxes[r])
                mem[l][r][k] = max(mem[l][r][k], dfs(boxes, mem, l, i, k + 1) + dfs(boxes, mem, i + 1, r - 1, 0));
        }
        return mem[l][r][k];
    }
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        int mem[100][100][100] = {0};
        return dfs(boxes, mem, 0, n - 1, 0);
    }
};
//DFS with mem (dp)
//https://leetcode.com/problems/remove-boxes/discuss/101312/Memoization-DFS-C%2B%2B
//mem[l][r][k]表示从boxes的第i(从0开始)个到第j个(包括)，且j后有k个与boxes[j]相同的情况下，取得的最大值
//核心是处理EEABCDAAAA中A这种情况
//mem[0][6][3] = max(mem[0][6][3], mem[0][2][4] + mem[3][5][0])