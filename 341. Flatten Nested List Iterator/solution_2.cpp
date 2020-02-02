/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    stack<NestedInteger> st;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; -- i)
            st.push(nestedList[i]);
    }

    int next() {
        NestedInteger top = st.top();
        st.pop();
        return top.getInteger();
    }

    bool hasNext() {
        if (st.empty())
            return false;
        NestedInteger top = st.top();
        if (top.isInteger())
            return true;
        while (!top.isInteger()) {  //防止[[-1],[],[]]
            st.pop();
            for (int i = top.getList().size() - 1; i >= 0; -- i)
                st.push(top.getList()[i]);
            if (st.empty())
                return false;
            top = st.top();
        }
        return true;
    }
};
//DFS
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */