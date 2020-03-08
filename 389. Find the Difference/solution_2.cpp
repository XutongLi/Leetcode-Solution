class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = 0;
        for (auto c : t)
            res ^= c - 'a';
        for (auto c : s) 
            res ^= c - 'a';
        return res + 'a';
    }
};
//bit manipulation
//通过xor消去相同数字