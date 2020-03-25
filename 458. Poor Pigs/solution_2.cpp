class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int gap = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(gap));
    }
};
//pow(minutesToTest / minutesToDie + 1, cnt)为cnt只猪在minutesToTest里最多可测试的数量
//pow(minutesToTest / minutesToDie + 1, cnt) >= buckets
//log(buckets) <= cnt * log(gap)
//cnt >= log(buckets) / log(gap)
//cnt_min = ceil(log(buckets) / log(gap))
//https://leetcode.com/problems/poor-pigs/discuss/94266/Another-explanation-and-solution