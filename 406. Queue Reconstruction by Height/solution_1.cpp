class Solution {
private:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res(people.size(), vector<int>(1));
        if (people.empty())
            return res;
        sort(people.begin(), people.end(), cmp);
        for (auto pair : people) {
            int k = pair[1], i = 0;
            for (; k > 0 || res[i].size() == 2; ++ i) {
                if (k > 0 && (res[i].size() != 2 || res[i][0] >= pair[0]))
                    -- k;   //有空位或者比pair大的，k递减
            }
            res[i] = pair;
        }
        return res;
    }
};
//O(n^2)
//先放小的，再放大的
//-   -    -   -   4,4  -
//5,0 -   5,2  -   4,4  -
//5,0 -   5,2  6,1 4,4  -
//5,0 7,0 5,2  6,1 4,4 7,1