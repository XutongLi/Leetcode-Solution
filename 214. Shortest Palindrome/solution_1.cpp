class Solution {
private:
    bool getPalin(string &s, int idx, string &res) {
        bool ret = true;
        //以两个字符为中心（优先以两个字符为中心，这样res长度更短）
        int l = idx, r = idx + 1;
        if (l + 1 <= s.size() - r) {    //l左侧元素小于等于r右侧元素时
            while (l >= 0) {
                if (s[l --] != s[r ++]) {
                    ret = false;
                    break;
                }
            }
            if (ret) {
                while (r < s.size()) 
                    res = string(1, s[r ++]) + res;
                res += s;
                return ret;
            }
        }
        //以一个字符为中心
        ret = true;     l = idx;    r = idx;
        while (l >= 0) {
            if (s[l --] != s[r ++]) {
                ret = false;
                break;
            }
        }
        if (ret) {
            while (r < s.size()) 
                res = string(1, s[r ++]) + res;
            res += s;
        }
        return ret;
    }
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string res = "";
        for (int i = (n - 1) / 2; i >= 0; -- i) {   //因为在s前添加字符，当i>(n-1)/2时左侧长度大于右侧，不符合条件
            if (getPalin(s, i, res))    //i越靠后，res长度越短
                return res;
        }
        return res;
    }
};
//time O(n^2)