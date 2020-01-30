class Solution {
public:
    int getSum(int a, int b) {
        while (b) { 
            int tmp = a ^ b;    //按位相加时，不考虑进位，结果与异或相同
            b = (unsigned int)(a & b) << 1;   //进位与两者相与结果相同（同为1时进位），进位结果左移一位与异或结果相加
            a = tmp;            //重复1,2步组成的加法，直至没有进位（即b为0）
        }                       //使用unsigned int防止溢出
        return a;   
    }
};