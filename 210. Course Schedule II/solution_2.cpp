class Solution {
private:
    using Graph = vector<unordered_set<int>>;
    //有环时返回true
    bool cyclic(int idx, const Graph &graph, vector<bool> &flag, unordered_set<int> &visited, vector<int> &res) {
        flag[idx] = true;
        visited.insert(idx);
        for (auto next : graph[idx]) {
            if (visited.find(next) != visited.end())
                return true;
            if (!flag[next] && cyclic(next, graph, flag, visited, res))
                return true;
        }
        res.push_back(idx);
        visited.erase(idx);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prelist) {
        Graph graph(numCourses);
        for (auto vec : prelist) {
            graph[vec[1]].insert(vec[0]);
        }
        vector<bool> flag(numCourses, false);
        unordered_set<int> visited;
        vector<int> res;
        for (int i = 0; i < numCourses; ++ i) {
            if (!flag[i] && cyclic(i, graph, flag, visited, res))
                return vector<int>();   //有环
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
//DFS