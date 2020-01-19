class Solution {
private:
    struct cmp {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; 
        for (auto n : nums)
            ++ mp[n];
        for (auto p : mp) {
            pq.push(p);
            if (pq.size() > k)
                pq.pop();
        }
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
//使用小根堆，最后留下k个最大的
//O(nlogk)