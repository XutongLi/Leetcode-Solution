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
    string getKey(vector<int> &p1, vector<int> &p2) {   //key形式为y=kx+b
        string res;
        if (p1[0] == p2[0]) {
            res = "x=" + to_string(p1[0]);
        }
        else if (p1[1] == p2[1]) {
            res = "y=" + to_string(p1[1]);
        }
        else {
            long long y = p2[1] - p1[1], x = p2[0] - p1[0];
            int mea = measure(y, x);
            y = y / mea;
            x = x / mea;
            res = "y=" + to_string(y) + "/" + to_string(x) + "x";   //k
            y = (ll)p1[0] * (ll)p2[1] - (ll)p2[0] * (ll)p1[1], x = p1[0] - p2[0];
            mea = measure(y, x);
            y = y / mea;
            x = x / mea;
            res += "+" + to_string(y) + "/" + to_string(x); //b
        }
        return res;
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 2)
            return points.size();
        int m = points.size();
        unordered_map<string, unordered_set<int>> mp;
        for (int i = 0; i < m - 1; ++ i) {
            for (int j = i + 1; j < m; ++ j) {
                mp[getKey(points[i], points[j])].insert(i);
                mp[getKey(points[i], points[j])].insert(j);
            }
        }
        int maxi = INT_MIN;
        for (auto p : mp) {
            maxi = max(maxi, static_cast<int>(p.second.size()));
        }
        return maxi;
    }
};