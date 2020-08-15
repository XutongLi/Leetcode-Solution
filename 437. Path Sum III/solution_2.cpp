/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void pathSum(TreeNode *root, int sum, int cur, unordered_map<int, int> &preSum, int &res) {
        if (!root)  return;
        cur += root->val;
        res += preSum[cur - sum];
        ++ preSum[cur];
        pathSum(root->left, sum, cur, preSum, res);
        pathSum(root->right, sum, cur, preSum, res);
        -- preSum[cur];
    }
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> preSum;
        preSum[0] = 1;
        int res = 0;
        pathSum(root, sum, 0, preSum, res);
        return res;
    }
};

// based on https://leetcode.com/problems/subarray-sum-equals-k/