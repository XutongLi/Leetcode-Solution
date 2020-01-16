class Solution {
private:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(), people.end(), cmp);
        for (auto pair : people) {
            res.insert(res.begin() + pair[1], pair);
        }
        return res;
    }
};
//O(nlong)
//先放大的，再插入小的
//7,0
//7,0  7,1
//7,0  6,1  7,1
//5,0  7,0  6,1  7,1
//5,0  7,0  5,2  6,1  7,1
//5,0  7,0  5,2  6,1  4,4  7,1