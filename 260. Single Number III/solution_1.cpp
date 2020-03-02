class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int axorb = 0;
        for (auto n : nums)
            axorb ^= n;     //num1 xor num2
        int lastDiff = axorb & (-axorb);    //求出num1和num2有差异的最右一位（-x表示将x去反加1）
        int num1 = 0, num2 = 0;
        for (auto n : nums) {
            if (n & lastDiff)   //通过差异位来区分num1和num2，其他数字在xor过程中消去
                num1 ^= n;
            else
                num2 ^= n;
        }
        return vector<int>{num1, num2};
    }
};
