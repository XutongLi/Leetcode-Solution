// Bellman-Ford
class Solution {
private:
    const int INF = 1e9;
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dis(N + 1, INF);
        dis[K] = 0;
        for (int i = 1; i <= N; ++ i ) {
            for (auto vec : times) {
                if (dis[vec[0]] + vec[2] < dis[vec[1]])
                    dis[vec[1]] = dis[vec[0]] + vec[2];
            }
        }
        int res = *max_element(dis.begin() + 1, dis.end());
        return res == INF ? -1 : res;
    }
};
// O(EV)