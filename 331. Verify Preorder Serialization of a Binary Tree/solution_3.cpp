class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<string> st;
        stringstream str(preorder);
        string tmp;
        while (getline(str, tmp, ',')) {
            while (tmp == "#" && !st.empty() && st.top() == "#") {
                st.pop();   //pop #
                if (st.empty())
                    return false;
                st.pop();   //pop num
            }
            st.push(tmp);
        }
        return st.size() == 1 && st.top() == "#";
    }
};
//stack solution
//当stack中#凑成一对时，pop stack顶部的一个#和数字