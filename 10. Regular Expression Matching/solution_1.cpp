class Solution {
private:
	bool isMatch(string &s, int st, string &p, int pt) {
		int ls = s.size() - st, lp = p.size() - pt;
        if (lp == 0)	return ls == 0;
        bool firstMatch = (ls > 0) && (s[st] == p[pt] || p[pt] == '.');
        if (lp >= 2 && p[pt + 1] == '*')
            return firstMatch && isMatch(s, st + 1, p, pt) || isMatch(s, st, p, pt + 2);
        else 
            return firstMatch && isMatch(s, st + 1, p, pt + 1);
    }
public:
    bool isMatch(string &s, string &p) {
        return isMatch(s, 0, p, 0);
    }
};
