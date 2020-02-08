class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (auto n : nums) {
            ones = (ones ^ n) & ~twos;
            twos = (twos ^ n) & ~ones;
        }
        return ones;
    }
};
//以3个4为例
//对于第一个4，ones保存它，twos不保存
//对于第二个4，ones清除它，twos保存它
//对于第三个4，ones和twos都清除它
//所以ones最后保存只出现一次的数字，出现3次的都被清零

//因为twos中存在某数，ones中便要清除它，所以 ones = (ones ^ n) & ~twos
//因为ones中存在某数，twos中便要清除它，所以 twos = (twos ^ n) & ~ones