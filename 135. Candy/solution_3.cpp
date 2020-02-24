class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0)
            return 0;
        int  pre = 1, countDown = 0, res = 1;
        for (int i = 1; i < n; ++ i) {
            if (ratings[i] >= ratings[i - 1]) {
                if (countDown > 0) {
                    res += (1 + countDown) * countDown / 2;     //下坡求和
                    if (countDown >= pre)
                        res += countDown - pre + 1;     //补充坡顶值（因为坡底必为1，原坡顶值可能不够）
                    pre = 1;
                    countDown = 0;
                }
                pre = (ratings[i] == ratings[i - 1]) ? 1 : pre + 1; //rate与上一个相等时，此位置为1
                res += pre;     //上坡时添加到res
            }
            else
                ++ countDown;
        }
        if (countDown > 0) {
            res += (1 + countDown) * countDown / 2;
            if (countDown >= pre)
                res += countDown - pre + 1;
        }
        return res;
    }
};
//greedy time
//time O(n) space O(1)
//http://www.allenlipeng47.com/blog/index.php/2016/07/21/candy/