//100%
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null)   return false;
        if (root.left == null && root.right == null && sum == root.val)
            return true;
        boolean res = false;
        if (root.left != null)
            res = res || hasPathSum(root.left, sum - root.val);
        if (root.right != null)
            res = res || hasPathSum(root.right, sum - root.val);
        return res;
    }
}