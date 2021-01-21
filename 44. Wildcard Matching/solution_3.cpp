class Solution {
private:
    bool isMatch(string &s, int sidx, string &p, int pidx, vector<vector<int>> &mem) {
        int slen = s.size() - sidx, plen = p.size() - pidx;
        if (plen == 0)  return slen == 0;
        if (slen == 0)  return p[pidx] == '*'? isMatch(s, sidx, p, pidx + 1, mem) : false;
        if (mem[sidx][pidx] != -1)
            return mem[sidx][pidx];
        if (s[sidx] == p[pidx] || p[pidx] == '?')
            mem[sidx][pidx] = isMatch(s, sidx + 1, p, pidx + 1, mem);
        else if (p[pidx] == '*')
            mem[sidx][pidx] = isMatch(s, sidx, p, pidx + 1, mem) || isMatch(s, sidx + 1, p, pidx, mem);
        else 
            mem[sidx][pidx] = false;
        return mem[sidx][pidx];
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> mem(s.size(), vector<int>(p.size(), -1));
        return isMatch(s, 0, p, 0, mem);
    }
};
// DFS with memorization