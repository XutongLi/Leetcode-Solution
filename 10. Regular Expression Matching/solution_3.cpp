class Solution {
private:
	bool isMatch(string &s, int st, string &p, int pt, vector<vector<int>> &mem) {
		int ls = s.size() - st, lp = p.size() - pt;
        if (lp == 0)	return ls == 0;
        if (mem[st][pt] != -1)
            return mem[st][pt];
        bool firstMatch = (ls > 0) && (s[st] == p[pt] || p[pt] == '.');
        if (lp >= 2 && p[pt + 1] == '*') {
            bool ret = firstMatch && isMatch(s, st + 1, p, pt, mem) || isMatch(s, st, p, pt + 2, mem);
            mem[st][pt] = ret;
            return ret;
        }
        else {
            bool ret = firstMatch && isMatch(s, st + 1, p, pt + 1, mem);
            mem[st][pt] = ret;
            return ret;
        }
    }
public:
    bool isMatch(string &s, string &p) {
        vector<vector<int>> mem(s.size() + 1, vector<int>(p.size() + 1, -1));
        mem[s.size()][p.size()] = 1;
        return isMatch(s, 0, p, 0, mem);
    }
};
