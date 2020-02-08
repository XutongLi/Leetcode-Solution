class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        uint32_t mask = 1;
        for (int i = 0; i < 32; ++ i) {
            int cnt = 0;
            for (auto &n : nums) {
                if (n & mask)       //n&mask最后一位为1时，true
                    ++ cnt;
            }
            if (cnt % 3)    //cnt%3=1时 true
                res |= mask;
            mask = mask << 1;
        }
        return res;
    }
};
//011 011 011 100 100 100 010
//i = 0, cnt = 3, res = 0
//i = 1, cnt = 4, res = 0|10 = 10
//i = 2, cnt = 3, res = 10