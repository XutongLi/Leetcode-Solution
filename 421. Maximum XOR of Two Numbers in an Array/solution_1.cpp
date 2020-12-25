class Trie {
private:
    Trie *next[2] = {};
public:
    void insert(int num) {
        auto node = this;
        for (int i = 30; i >= 0; -- i) {
            int cur = (num >> i) & 1;
            if (!node->next[cur])
                node->next[cur] = new Trie();
            node = node->next[cur];
        }
    }
    int search(int num) {
        int sum = 0;
        auto node = this;
        for (int i = 30; i >= 0; -- i) {
            int cur = (num >> i) & 1;
            if (node->next[cur ^ 1]) {
                sum += (1 << i);
                node = node->next[cur ^ 1];
            } 
            else {
                node = node->next[cur];
            }
        }
        return sum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        if (nums.empty())   return 0;
        int res = 0;
        Trie *trie = new Trie();
        for (auto num : nums)
            trie->insert(num);
        for (auto num : nums)
            res = max(res, trie->search(num));
        return res;
    }
};