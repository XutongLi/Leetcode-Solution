class Solution {
private:
    int build(const string &str, int idx) {
        if (idx > str.size())   //#不够
            return str.size() + 1;  
        if (str[idx ++] == '#') {
            return idx;
        }
        else {
            while (isdigit(str[idx]))
                ++ idx;     //获取数字后一个逗号
            int left = build(str, idx + 1);     //左子树最后一个逗号位置
            int right = build(str, left + 1);   //右子树最后一个逗号位置
            return right;   
        }
    }
public:
    bool isValidSerialization(string preorder) {
        return build(preorder, 0) == preorder.size();   
    }
};
//preorder traversal