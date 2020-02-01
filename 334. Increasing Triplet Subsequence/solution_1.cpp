class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX, big = INT_MAX;
        for (auto n : nums) {
            if (n <= small)
                small = n;
            else if (n <= big)
                big = n;
            else
                return true;
        }
        return false;
    }
};
//O(n)
//更新完small后，当出现比small大的值时会更新big，之后small不会再更新。
//之后更新big，当找到比两者都大的元素时，确定存在