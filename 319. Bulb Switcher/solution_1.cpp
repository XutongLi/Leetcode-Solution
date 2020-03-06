class Solution {
public:
    int bulbSwitch(int n) {
        int cnt = 0;
        for (int i = 1; i * i <= n; ++ i)
            ++ cnt;
        return cnt;
    }
};
//time O(n)
//如第9个灯泡，第1,3,9次改变状态，修改次数为奇数，则最后亮，所以第i个要亮，i必为完全平方数
//https://leetcode.com/problems/bulb-switcher/discuss/77133/My-0-ms-C%2B%2B-solution-with-explanation