class Solution {
private:
    int dfs(const vector<vector<int>> &sv, unordered_map<string, int> &mp, string target) {
        if (mp.find(target) != mp.end())    //在memory中查到时直接返回
            return mp[target];
        vector<int> tv(26, 0);
        for (auto c : target)
            ++ tv[c - 'a'];
        int mini = INT_MAX;
        for (int i = 0; i < sv.size(); ++ i) {
            if (sv[i][target[0] - 'a'] == 0)    //仅用于优化
                continue;
            string s = "";
            for (int j = 0; j < 26; ++ j) {
                if (tv[j] > sv[i][j])   //当这个sticker不足够组成target时，将target中多余的组成s
                    s += string(tv[j] - sv[i][j], 'a' + j); //s为
            }
            int remain = dfs(sv, mp, s);    //查询组成s最少需要多少sticker
            if (remain != -1)
                mini = min(mini, 1 + remain);
        }
        mp[target] = (mini == INT_MAX ? -1 : mini);     //无法组成时返回-1
        return mp[target];
    }
public:
    int minStickers(vector<string>& stickers, string target) {
        int slen = stickers.size();
        unordered_map<string, int> mp;  //mp key为string，val为组成该string所需的最少sticker
        vector<vector<int>> sv(slen, vector<int>(26, 0));
        for (int i = 0; i < slen; ++ i) {
            for (auto c : stickers[i]) {
                ++ sv[i][c - 'a'];
            }
        }
        mp[""] = 0;
        return dfs(sv, mp, target);
    }
};
//DFS with memorization (also DP)
//https://leetcode.com/problems/stickers-to-spell-word/discuss/108318/C%2B%2BJavaPython-DP-%2B-Memoization-with-optimization-29-ms-(C%2B%2B)