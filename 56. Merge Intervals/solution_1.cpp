class Solution {
private:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty())
            return res;
        sort(intervals.begin(), intervals.end(), cmp);
        for (auto vec : intervals) {
            if (res.empty()) {
                res.push_back(vec);
                continue;
            }            
            if (vec[0] > res[res.size() - 1][1])
                res.push_back(vec);
            else 
                res[res.size() - 1][1] = max(res[res.size() - 1][1], vec[1]);
        }
        return res;
    }
};  //O(nlogn) 