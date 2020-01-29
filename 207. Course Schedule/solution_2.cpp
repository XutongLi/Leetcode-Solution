class Solution {
private:
    typedef vector<unordered_set<int>> Graph;
    //return true if cycle exists
    bool DFS(int i, const Graph &graph, unordered_set<int> &visited, vector<bool> &flag) {
        flag[i] = true;
        visited.insert(i);
        for (auto nei : graph[i]) {
            if (visited.find(nei) != visited.end() || !flag[nei] && DFS(nei, graph, visited, flag))
                return true;
        }
        visited.erase(i);
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph graph(numCourses);
        for (auto pair : prerequisites) {
            graph[pair[1]].insert(pair[0]);     //pair[1] -> pair[0]
        }
        vector<bool> flag(numCourses, false);
        unordered_set<int> visited;
        for (int i = 0; i < numCourses; ++ i) {
            if (!flag[i]) {
                if (DFS(i, graph, visited, flag))
                    return false;
            }
        }
        return true;
    }
};
//DFS