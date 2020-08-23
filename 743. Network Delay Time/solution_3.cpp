class Solution {
private:
    const int INF = 1e9;
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dis(N + 1, INF);
        dis[K] = 0;
        for (int i = 0; i < N; ++ i) {
            for (auto vec : times) {
                int from = vec[0], to = vec[1], time = vec[2];
                if (dis[to] > dis[from] + time)
                    dis[to] = dis[from] + time;
            }
        }
        int res = *max_element(dis.begin() + 1, dis.end());
        return res == INF ? -1 : res;
    }
};
// Bellman-Ford
// O(VE)  复杂度比较高，此题目易超时
// Bellman-Ford:边权可以为负，对所有边进行松弛操作，即估计的最短路径值渐渐地被更加准确的值替代，直至得到最优解。
// Dijstra:边权不可为负，以贪心法选取未被处理的具有最小权值的节点，然后对其的出边进行松弛操作
