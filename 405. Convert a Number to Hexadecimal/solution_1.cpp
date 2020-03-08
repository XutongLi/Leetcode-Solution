class Solution {
private:
    const string s = "0123456789abcdef";
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        string res = "";
        int cnt = 0;
        while (num && cnt ++ < 8) {
            res = s[num & 0xf] + res;   //0xf为15
            num >>= 4;
        }
        return res;
    }
};
//Bit Manipulation
//time O(logn)

//如-15 二进制表示为 111....0001
//所以结果为0xfffffff1