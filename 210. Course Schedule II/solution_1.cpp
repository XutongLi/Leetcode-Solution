class Solution {
private:
    using Graph = vector<unordered_set<int>>;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prelist) {
        Graph graph(numCourses);
        vector<int> inlist(numCourses, 0);     //入度list
        for (auto vec : prelist) {
            graph[vec[1]].insert(vec[0]);
            ++ inlist[vec[0]];
        }
        vector<int> res;
        for (int k = 0; k < numCourses; ++ k) {
            int i;
            for (i = 0 ; i < numCourses && inlist[i] != 0; ++ i);
            if (i == numCourses)
                return vector<int>();
            res.push_back(i);
            for (auto next : graph[i])
                -- inlist[next];
            inlist[i] = -1;
        }
        return res;
    }
};
//Topology Sort