class Solution {
private:
    unordered_map<char, int> mp;
    void init() {
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
    }
public:
    int romanToInt(string s) {
        init();
        int num = 0, i;
        for (i = 0; i < s.size() - 1; ++ i) {
            if (mp[s[i]] >= mp[s[i + 1]])
                num += mp[s[i]];
            else {
                num -= mp[s[i]];
                num += mp[s[++ i]];
            }
        }
        if (i == s.size() - 1)
            num += mp[s[i]];
        return num;
    }
};