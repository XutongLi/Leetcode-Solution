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
private:
    vector<TreeNode*> gen(int lo, int hi) {
        vector<TreeNode*> res;
        if (lo > hi) {  //如1, 0
            res.push_back(nullptr);
            return res;
        }
        for (int root = lo; root <= hi; ++ root) {
            vector<TreeNode*> left = gen(lo, root - 1);
            vector<TreeNode*> right = gen(root + 1, hi);
            for (auto lnode : left) {
                for (auto rnode : right) {
                    TreeNode *node = new TreeNode(root);
                    node->left = lnode;
                    node->right = rnode;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return vector<TreeNode*>();
        return gen(1, n);
    }
};
//分别以1-n作为根节点，如以i作为根节点，将1 - i-1组成的BST作为root的左节点， i+1 - n组成的BST作为root的右节点 