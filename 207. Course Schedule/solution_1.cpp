class Solution {
private:
    typedef vector<vector<int>> Graph;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto pair : prerequisites) {
            graph[pair[1]].push_back(pair[0]);     //pair[1] -> pair[0]
            ++ indegree[pair[0]];
        }
        for (int j = 0; j < numCourses; ++ j) {
            int i;
            for (i = 0; i < numCourses && indegree[i] != 0; ++ i);  //find node whose indegree is 0
            if (i == numCourses)
                return false;
            for (auto nei : graph[i])
                -- indegree[nei];
            indegree[i] = -1;   //i has been visited, set -1
        }
        return true;
    }
};
//BFS Topology Sort
//https://blog.csdn.net/weixin_42001089/article/details/84327306