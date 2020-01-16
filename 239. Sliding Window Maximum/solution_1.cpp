class Solution {
private:
    struct cmp {
        bool operator () (const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
        }   //令优先队列从大到小排列
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.size() <= 1 || k == 1)
            return nums;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (int i = 0; i < k; ++ i) {
            pq.push(make_pair(i, nums[i]));
        }
        res.push_back(pq.top().second);
        for (int i = k; i < nums.size(); ++ i) {
            while (!pq.empty() && i - pq.top().first >= k) {
                pq.pop();
            }
            pq.push(make_pair(i, nums[i]));
            res.push_back(pq.top().second);
        }
        return res;
    }
};