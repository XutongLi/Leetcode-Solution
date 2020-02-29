class Solution {
public:
    int countDigitOne(int n) {
        if (n < 1)
            return 0;
        int res = 0;
        for (long long i = 1; i <= n; i *= 10) {
            int cur = (n / i) % 10;     //当前位，对于n=12013，i=100，cur=0
            int high = n / (i * 10);    //高位，high=12
            int low = n % i;            //低位，low=13
            if (cur == 0)
                res += high * i;
            else if (cur == 1)
                res += high * i + low + 1;
            else
                res += (high + 1) * i;
        }
        return res;
    }
};
//time O(logn) space O(1)
//依次计算每一位上1的个数
//如计算百位，对于12013，百位上1的个数为12*100
//对于12113，百位上1的个数为12*100+12+1
//对于12213，百位上的个数为(12+1)*100