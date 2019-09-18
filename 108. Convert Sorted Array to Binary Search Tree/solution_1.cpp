/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return NULL;
        return binaryTree(nums, 0, len - 1);
    }
    TreeNode* binaryTree(vector<int> nums, int lo, int hi) {
        if (lo > hi)
            return NULL;
        int mid = (hi + lo) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = binaryTree(nums, lo, mid - 1);
        node->right = binaryTree(nums, mid + 1, hi);
        return node;
    }
};