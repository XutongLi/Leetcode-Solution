class Solution {
private:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int> q;
        int now = 0;
        for (auto vec : courses) {
            q.push(vec[0]);
            now += vec[0];
            if (now > vec[1]) {
                now -= q.top();
                q.pop();
            }
        }
        return q.size();
    }
};
//greedy
//time O(nlogn)  space O(1)
//先按截止日期从小到大排序，然后逐个累加时间，若超出期限，减去已累计科目中时间最长的，此时保留的便是到此截止日期所累积的最短时间