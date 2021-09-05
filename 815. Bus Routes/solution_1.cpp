class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < routes.size(); ++ i) {
            for (int n : routes[i]) {
                g[n].push_back(i);
            }
        }
        queue<pair<int, int>> q;
        unordered_set<int> visited;
        q.push({source, 0});
        visited.insert(source);
        while (!q.empty()) {
            int len = q.size();
            while (len --) {
                int station = q.front().first;
                int cnt = q.front().second;
                if (station == target)
                    return cnt;
                q.pop();
                for (auto &nexts : g[station]) {
                    for (auto next : routes[nexts])
                        if (visited.find(next) == visited.end()) {
                            q.push({next, cnt + 1});
                            visited.insert(next);
                        }
                    routes[nexts].clear();
                }
            }
        }
        return -1;
    }
};