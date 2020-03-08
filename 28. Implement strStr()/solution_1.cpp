class Solution {
private:
    //getNext实际使用needle匹配needle
    void getNext(const string &needle, vector<int> &next) {
        int i = 1, len = 0;
        while (i < needle.size()) {
            if (needle[i] == needle[len])
                next[i ++] = ++ len;
            else if (len == 0)  //needle[i] != needle[len]
                next[i ++] = 0;
            else
                len = next[len - 1];
        }
    }
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (n == 0)
            return 0;
        vector<int> next(n, 0);
        getNext(needle, next);
        int i = 0, j = 0;
        while (i <= m) {
            if (j == n)     //j到达needle尾后位，匹配成功
                return i - j;
            if (i == m)     //i到达haystack尾后位，匹配失败
                return -1;
            if (haystack[i] == needle[j]) {
                ++ i;   ++ j;
            }
            else if (j == 0)    // haystack[i] != needle[j]
                ++ i;
            else 
                j = next[j - 1];
        }
        return -1;
    }
};
//KMP
//time O(m + n) space O(n)
//匹配过程描述：https://blog.csdn.net/f1033774377/article/details/82556438