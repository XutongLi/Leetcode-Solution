class Solution {
private:
    class TreeNode {
    public:
        TreeNode *left, *right;
        int sum, dup, val;
        TreeNode(int _val, int _sum, int _dup) {
            left = right = nullptr;
            val = _val;
            sum = _sum;     //左下侧节点数量
            dup = _dup;
        }
    };
    TreeNode *insert(int num, TreeNode *node, int &cnt, int preSum) {
        if (node == nullptr) {
            node = new TreeNode(num, 0, 1);
            cnt = preSum;
        }
        else if (num == node->val) {
            ++ node->dup;
            cnt = preSum + node->sum;
        }
        else if (num < node->val) {
            ++ node->sum;
            node->left = insert(num, node->left, cnt, preSum);
        }
        else {  //num > node->val
            node->right = insert(num, node->right, cnt, preSum + node->dup + node->sum);
        }
        return node;
    } 
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> cnt(nums.size());
        TreeNode *root = nullptr;
        for (int i = nums.size() - 1; i >= 0; -- i) {
            root = insert(nums[i], root, cnt[i], 0);
        }
        return cnt;
    }
};
//BST O(nlogn)
//https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/76580/9ms-short-Java-BST-solution-get-answer-when-building-BST