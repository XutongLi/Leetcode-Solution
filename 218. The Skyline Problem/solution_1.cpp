class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> x_h;
        int left, right, height;
        for (auto build : buildings) {
            left = build[0];
            right = build[1];
            height = build[2];
            //为了将当left相同时，将height大的排在前，且通过正负可区分left和right
            x_h.push_back({left, -height});
            x_h.push_back({right, height});
        }
        sort(x_h.begin(), x_h.end());   //从小到大排序，first相同时second从小到大排序
        multiset<int> m;    //用来记录高度，默认从小到大排序
        m.insert(0);
        int cur = 0, pre = 0;
        vector<vector<int>> res;
        for (auto &p : x_h) {
            int x = p.first, h = p.second;
            if (h < 0)  //到left
                m.insert(-h);
            else    //到right时
                m.erase(m.find(h)); //将h删除（不用优先队列的原因在此，优先队列无法对指定元素删除）
            cur = *(m.rbegin());   //最后一位，即当前最大高度
            if (cur != pre) {   //最大高度有更新
                res.push_back(vector<int>{x, cur});
                pre = cur;
            }
        }
        return res;
    }
};
//使用multiset
//O(nlogn)
//https://leetcode.com/problems/the-skyline-problem/discuss/61259/recommend-for-beginnersclean-C%2B%2B-implementation-with-detailed-explanation