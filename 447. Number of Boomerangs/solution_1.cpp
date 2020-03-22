class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        for (int i = 0; i < n; ++ i) {
            unordered_map<long, int> mp;   
            for (int j = 0; j < n; ++ j) {
                if (i == j) continue;
                long dis = pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2);
                if (mp.find(dis) != mp.end()) 
                    res += 2 * mp[dis];
                ++ mp[dis];
            }
        }
        return res;
    }
};
//O(n^2)