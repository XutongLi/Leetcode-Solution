class Solution {
public:
    bool canCross(vector<int>& stones) {
        int len = stones.size();
        stack<pair<int, int>> st;   //stone idx - 可到达此stone的unit数
        unordered_set<long> visited;
        st.push(make_pair(0, 0));
        while (!st.empty()) {
            int pos = st.top().first;
            int unit = st.top().second;
            st.pop();
            
            long id = pos;
            id =  ((id << 32) | unit);  //id为pos和unit共同组成的，作为key，表明pos前进unit数不可能到达stones[len-1]
            if (visited.find(id) != visited.end())  //没有这个判断会超时
                return false;
            
            for (int j = pos + 1; j < len; ++ j) {
                int dis = stones[j] - stones[pos];
                if (dis < unit - 1)
                    continue;
                if (dis > unit + 1) {
                    if (j == len - 1)
                        visited.insert(id); //pos前进unit数不可能到达stones[len-1]
                    break;
                }
                if (j == len - 1)
                    return true;
                st.push(make_pair(j, dis));
            }
        }
        return false;
    }
};
//stack solution
//time O(n) ~ O(n^2)
//因为每次从栈顶取元素，所以尽可能最远地向后移动，所以耗时短
//8ms