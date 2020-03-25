class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int cnt = 0;
        while (pow(minutesToTest / minutesToDie + 1, cnt) < buckets)
            ++ cnt;
        return cnt;
    }
};
//pow(minutesToTest / minutesToDie + 1, cnt)为cnt只猪在minutesToTest里最多可测试的数量
//https://leetcode.com/problems/poor-pigs/discuss/94266/Another-explanation-and-solution