class Solution {
private:
    struct cmp {
        bool operator() (const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
            return a.first > b.first;
        }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
        pq.push({matrix[0][0], {0, 0}});
        pair<int, pair<int, int>> p;
        while (k --) {
            p = pq.top();
            pq.pop();
            int x = p.second.first;
            int y = p.second.second;
            if (x < m - 1) {
                pq.push({matrix[x + 1][y], {x + 1, y}});
            }
            if (x == 0 && y < n - 1) {
                pq.push({matrix[x][y + 1], {x, y + 1}});
            }
        }
        return p.first;
    }
};
//O(klogn)