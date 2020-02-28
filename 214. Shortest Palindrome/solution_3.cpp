class Solution {
public:
    string shortestPalindrome(string s) {
        string v = s;
        reverse(v.begin(), v.end());
        string str = s + "#" + v;
        int n = s.size(), sn = str.size();
        vector<int> next(sn, 0);
        for (int i = 1, len = 0; i < sn; ) {
            if (str[i] == str[len]) 
                next[i ++] = ++ len;
            else if (len == 0)
                next[i ++] = 0;
            else
                len = next[len - 1];
        }
        return v.substr(0, n - next[sn - 1]) + s;
    }
};
//使用KMP算法next数组求解方法 time O(n) space O(n)
//对于abacd
//abacd#dcaba     
//00100000123 (next[])
//dc(v.sub(0,n - next[n_new-1])) + s
//awesome solution