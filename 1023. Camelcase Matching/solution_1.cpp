class Solution {
private:
    bool islowercase(char c) {
        if (c >= 'a' && c <= 'z')
            return true;
        else
            return false;
    }
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (string w : queries) {
            int j = 0;
            bool hasUpper = false;
            for (int i = 0; i < w.size(); ++ i) {
                if (j < pattern.size() && w[i] == pattern[j])   ++ j;
                else if (!islowercase(w[i])) {
                    hasUpper = true;
                    break;
                }
            }
            if (j == pattern.size() && !hasUpper)
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};