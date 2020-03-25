class Solution {
private:
    using Graph = unordered_map<string, unordered_map<string, double>>;
    double dfs(Graph &graph, unordered_set<string> &visited, string start, string target) {
        if (start == target)
            return 1;
        visited.insert(start);
        for (auto p : graph[start]) {
            if (visited.find(p.first) != visited.end())
                continue;
            double ret = dfs(graph, visited, p.first, target);
            if (ret != -1) {
                return ret * p.second;
            }
        }
        return -1;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        Graph graph;
        for (int i = 0; i < equations.size(); ++ i) {
            graph[equations[i][0]].insert({equations[i][1], values[i]});
            graph[equations[i][1]].insert({equations[i][0], 1 / values[i]});
        }
        for (auto p : queries) {
            if (graph.find(p[0]) == graph.end() || graph.find(p[1]) == graph.end()) {
                res.push_back(-1);  //有端点不存在
                continue;
            }
            unordered_set<string> visited;
            res.push_back(dfs(graph, visited, p[0], p[1]));
        }
        return res;
    }
};
//Graph + DFS