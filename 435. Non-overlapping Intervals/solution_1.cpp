class Solution {
private:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[1] == b[1])
            return a[0] > b[0];
        else
            return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int res = 0;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++ i) {
            if (intervals[i][0] < end)
                ++ res;
            else
                end = intervals[i][1];
        }
        return res;
    }
};
//greedy
//time O(nlogn)  space O(1)
//将结束早的排在前面，同时结束短的排在前面