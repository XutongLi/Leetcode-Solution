class Solution {
private:
    class Trie {
    public:
        Trie *next[2] = {};
    };
    Trie *trie;
    void insert(vector<int> &nums) {
        for (auto n : nums) {
            auto node = trie;
            for (int i = 30; i >= 0; -- i) {
                int idx = (n >> i) & 1;
                if (!node->next[idx])
                    node->next[idx] = new Trie();
                node = node->next[idx];
            }
        }
    }
    int search(Trie *node, int num, int up, int ele, int height) {  // ele is the choosen num
        if (ele > up)   return -1;
        if (height == -1)
            return ele ^ num;
        
        int bit = (num >> height) & 1;
        if (node->next[bit ^ 1]) {
            int ret = search(node->next[bit ^ 1], num, up, ele | ((bit ^ 1) << height), height - 1);
            if (ret != -1)  return ret;
        }
        if (node->next[bit]) {
            int ret = search(node->next[bit], num, up, ele | (bit << height), height - 1);
            if (ret != -1)  return ret;
        }
        return -1;
    }
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        trie = new Trie();
        insert(nums);
        vector<int> ret;
        for (auto vec : queries) {
            int res = search(trie, vec[0], vec[1], 0, 30);
            ret.push_back(res);
        }
        return ret;
    }
};

//Trie + DFS