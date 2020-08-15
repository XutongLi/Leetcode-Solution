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
    int count = 0;
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        countNode(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return count;
    }
    void countNode(TreeNode* root, int sum) {
        if (root == NULL)
            return;
        if (root->val == sum)
            count ++;
        countNode(root->left, sum - root->val);
        countNode(root->right, sum - root->val);
    }
};