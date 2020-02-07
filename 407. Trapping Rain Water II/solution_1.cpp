class Solution {
private:
    struct Point {
        int x = 0;
        int y = 0;
        int h = 0;
        Point(int i, int j, int k) : x(i), y(j), h(k) {}
    };
    struct cmp {    //高度小的先出
        bool operator() (const Point &a, const Point &b) {
            return a.h > b.h;
        }
    };
public:
    int trapRainWater(vector<vector<int>>& arr) {
        if (arr.empty())
            return 0;
        int m = arr.size(), n = arr[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<Point, vector<Point>, cmp> pq;
        //将四周加入优先队列
        for (int i = 0; i < m; ++ i) {
            pq.push(Point(i, 0, arr[i][0]));
            pq.push(Point(i, n - 1, arr[i][n - 1]));
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }
        for (int j = 0; j < n; ++ j) {
            pq.push(Point(0, j, arr[0][j]));
            pq.push(Point(m - 1, j, arr[m - 1][j]));
            visited[0][j] = true;
            visited[m - 1][j] = true;
        }
        vector<vector<int>> posi = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int res = 0;
        //从周围最低的位置开始遍历
        while (!pq.empty()) {
            auto point = pq.top();
            pq.pop();
            for (auto v : posi) {
                int x = point.x + v[0], y = point.y + v[1];
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y])
                    continue;
                res += max(0, point.h - arr[x][y]);
                pq.push(Point(x, y, max(point.h, arr[x][y])));  
                visited[x][y] = true;
            }
        }
        return  res;
    }
};
//BFS + priority queue
//time O(mnlogmn)  space O(mn)
//四面都是围墙，从最低的往里走
//如果里面有更低的，可以蓄水，蓄水的量就是围墙最低 减去 此处的高度
//如果里面的比当前围墙高，那这个方向的围墙高度就增加了
//然后永远围墙最低的地方开始搜，最后就能把整个水池搜一遍。