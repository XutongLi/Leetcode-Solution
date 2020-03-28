class Solution {
public:
    bool rotateString(string A, string B) {
        string com = A + '*' + B;
        vector<int> next(com.size(), 0);
        int len = 0, i = 1;
        while (i < com.size()) {
            if (com[i] == com[len])
                next[i ++] = ++ len;
            else if (len == 0)
                next[i ++] = 0;
            else
                len = next[len - 1];
        }
        int n = next[com.size() - 1];
        return A.substr(n) == B.substr(0, B.size() - n);
    }
};
//kmp 
//time O(a + b)  space O(a + b)