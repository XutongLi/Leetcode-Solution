class Solution {
private:
    using ll = long long;
    int measure(int x, int y) {		//求最大公约数
        if (y == 0)
            return x;
	    int z = y;
	    while(x % y != 0) {
		    z = x % y;
		    x = y;
		    y = z;	
	    }
	    return z;
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 2)
            return points.size();
        int m = points.size(), res = INT_MIN;
        for (int i = 0; i < m - 1; ++ i) {
            unordered_map<string, int> cnt;
            int same = 1, maxi = 0;
            for (int j = i + 1; j < m; ++ j) {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                if (x == 0 && y == 0) { //重复点
                    ++ same;
                    continue;
                }
                int g = measure(x, y);
                x /= g;
                y /= g;
                maxi = max(maxi, ++ cnt[to_string(x) + " " + to_string(y)]);
            }
            res = max(res, maxi + same);
        }
        return res;
    }
};