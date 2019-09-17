class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size();
        if (len == 1)
            return true;
        if (bits[len - 2] == 0)
            return true;
        int cnt = 0;
        for (int i = len - 2; i >= 0 && bits[i] == 1; i --)
                cnt ++;
        if (cnt % 2 == 1)
            return false;
        else
            return true;
    }
};