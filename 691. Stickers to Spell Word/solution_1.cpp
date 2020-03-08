class Solution {
private:
    void track(const vector<vector<int>> &sv, vector<int> &tv, int &len, int &cur, int &mini) {
        if (cur >= mini)    //当前长度已超过最小长度，不必再组合
            return;
        if (len == 0) {   //target已消去
            mini = min(mini, cur);
            return;
        }
        for (auto &vec : sv) {
            vector<int> tmp(tv);
            int tmpl = len;
            for (int i = 0; i < 26; ++ i) {
                int overlap = min(vec[i], tv[i]);
                tv[i] -= overlap;       //尽可能多地消去
                len -= overlap;

            }
            if (len < tmpl) {   //当target有消去，即vec和tv有重叠时
                cur += 1;
                track(sv, tv, len, cur, mini);
                tv = tmp;   //backtracking
                len = tmpl;
                cur -= 1;
            } 
        }
    }
public:
    int minStickers(vector<string>& stickers, string target) {
        vector<vector<int>> sv(stickers.size(), vector<int>(26, 0));
        vector<int> tv(26, 0);
        vector<bool> exist(26, false);  
        for (int i = 0; i < stickers.size(); ++ i) {
            for (auto c : stickers[i]) {
                ++ sv[i][c - 'a'];
                exist[c - 'a'] = true;
            }
        }
        for (auto c : target) {
            if (!exist[c - 'a'])    //sticker中没有，则返回-1
                return -1;
            ++ tv[c - 'a'];
        }
        int len = target.size(), cur = 0, mini = 16; //target最大长度为15，所以最多用15个（16作为一个最大值使用）
        track(sv, tv, len, cur, mini);
        return mini;
    }
};
//backtracking
//Time Limit Exceeded