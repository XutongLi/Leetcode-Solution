class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> mp1(10, 0);
        vector<int> mp2(10, 0);
        int len1 = secret.size(), len2 = guess.size(), i = 0, bull = 0, cow = 0;
        for (; i < min(len1, len2); ++ i) {
            if (secret[i] == guess[i])
                ++ bull;
            else {
                ++ mp1[secret[i] - '0'];
                ++ mp2[guess[i] - '0'];
            }
        }
        for (; i < len1; ++ i)      //两string长度不同时
            ++ mp1[secret[i] - '0'];
        for (; i < len2; ++ i)
            ++ mp2[guess[i] - '0'];
        for (int j = 0; j < 10; ++ j) 
            cow += min(mp1[j], mp2[j]);
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};