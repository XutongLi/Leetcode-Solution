class Solution {
private:
    int dfs(int amount, int idx, const vector<int>& coins, vector<unordered_map<int, int>> &mem) {
        if (amount == 0) 
            return 1;
        if (mem[idx].find(amount) != mem[idx].end())
            return mem[idx][amount];
        int cnt = 0;
        for (int i = idx; i < coins.size(); ++ i) {
            if (coins[i] > amount)
                break;
            cnt += dfs(amount - coins[i], i, coins, mem);
        }
        mem[idx][amount] = cnt;
        return cnt;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if (n == 0)     return amount == 0;
        sort(coins.begin(), coins.end());
        vector<unordered_map<int, int>> mem(n);
        return dfs(amount, 0, coins, mem);
    }
};
//dfs with mem
//mem[idx][amount]为从第idx个硬币开始，数量还剩amount可排列的次数