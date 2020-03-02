class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern.empty() || str.empty())
            return false;
        stringstream in(str);
        int n = pattern.size(), idx = 0;
        vector<int> pmp(26, 0);
        unordered_map<string, int> smp;
        for (string word; in >> word; ++ idx) {
            if (idx == n || pmp[pattern[idx] - 'a'] != smp[word])
                return false;
            pmp[pattern[idx] - 'a'] = idx + 1;
            smp[word] = idx + 1;
        }
        return idx == n;    //不等于时str单词数比pattern字母数多
    }
};
//use position as hash