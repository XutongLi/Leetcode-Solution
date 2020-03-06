class Solution {
public:
    bool isValidSerialization(string preorder) {
        int remain_cnt = 1;
        stringstream str(preorder);
        string tmp;
        while (getline(str, tmp, ',')) {
            -- remain_cnt;
            if (remain_cnt < 0)
                return false;
            if (tmp != "#")
                remain_cnt += 2;
        }
        return remain_cnt == 0;
    }
};
//special solution
//每遍历一个元素，剩余节点减一
//每到一个非','元素，剩余节点增加2