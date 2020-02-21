class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2)   
            return true;
        int l1 = s1.size(), l2 = s2.size();
        if (l1 != l2)
            return false;
        vector<int> cnt(26, 0);
        for (int i = 0; i < l1; ++ i) {
            ++ cnt[s1[i] - 'a'];
            -- cnt[s2[i] - 'a'];
        }
        for (auto n : cnt) {
            if (n != 0)    //各字母有数量不同的
                return false;
        }
        for (int i = 1; i < l1; ++ i) {   //分隔位置，第一个字母后分隔--最后一个字母前分隔
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, l1 - i), s2.substr(i, l1 - i)))
                return true;    //分割后直接递归
            if (isScramble(s1.substr(0, i), s2.substr(l1 - i, i))
                    && isScramble(s1.substr(i, l1 - i), s2.substr(0, l1 - i)))
                return true;    //分割后先交换两部分位置，再递归（做接下来的分隔以及交换）
        }
        return false;
    }
};
//递归写法
//每一部分分隔后有两种操作：1.做接下来的分隔与交换 2.先交换两部分，再做接下来的分隔与交换