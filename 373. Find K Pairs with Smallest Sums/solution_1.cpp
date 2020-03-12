class Solution {
private:
    struct cmp{
        bool operator()(const pair<int, vector<int>> &a, const pair<int, vector<int>> &b) {
            return a.first > b.first;
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, cmp> pq;
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 == 0 || n2 == 0)
            return res;
        unordered_set<string> st;
        pq.push(make_pair(nums1[0] + nums2[0], vector<int>{0, 0}));
        st.insert("0-0");
        while (k --) {
            if (pq.empty()) 
                break;
            auto front = pq.top();
            pq.pop();
            int i = front.second[0], j = front.second[1];
            res.push_back(vector<int>{nums1[i], nums2[j]});
            if (i < n1 - 1 && st.find(to_string(i + 1) + "-" + to_string(j)) == st.end()) {
                pq.push(make_pair(nums1[i + 1] + nums2[j], vector<int>{i + 1, j}));
                st.insert(to_string(i + 1) + "-" + to_string(j));
            }
            if (j < n2 - 1 && st.find(to_string(i) + "-" + to_string(j + 1)) == st.end()) {
                pq.push(make_pair(nums1[i] + nums2[j + 1], vector<int>{i, j + 1}));
                st.insert(to_string(i) + "-" + to_string(j + 1));
            }
        }
        return res;
    }
};
//time O(klogk)  space O(k)