class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if (intervals.empty()) {
            res.push_back(newInterval);
            return res;
        }
        if (newInterval.empty())
            return intervals;
        bool newPut = false;    //newInterval放入后为true
        for (auto inter : intervals) {
            if (newPut) {   //newInterval已存入res
                res.push_back(inter);
            }
            else if (inter[1] < newInterval[0])
                res.push_back(inter);
            else if (inter[0] > newInterval[1]) {
                res.push_back(newInterval);
                res.push_back(inter);
                newPut = true;
            }
            else {
                newInterval[0] = min(inter[0], newInterval[0]);
                newInterval[1] = max(inter[1], newInterval[1]);
            }
        }
        if (!newPut)
            res.push_back(newInterval);
        return res;
    }
};
//time O(n) space O(1)