class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), res = 0;
        vector<int> mask(n, 0);
        for (int i = 0; i < n; ++ i) {
            for (auto c : words[i])
                mask[i] |= 1 << (c - 'a');
            for (int j = 0; j < i; ++ j) {
                if (!(mask[i] & mask[j]))
                    res = max(res, static_cast<int>(words[i].size() * words[j].size()));
            }
        }
        return res;
    }
};
//bit manipulation
//time O(n^2)  space O(n)
//26bit表示26个字母，将每个单词mask对应的子母位置1，两单词mask想&为0，则两者无公共letter