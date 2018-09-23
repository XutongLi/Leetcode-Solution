//85%
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
    public boolean isBalanced(TreeNode root) {
        return root == null || depth(root) != -1;     
    }
    private int depth(TreeNode node) {
        if (node == null)  return 0;
        int left_depth = depth(node.left);
        if (left_depth == -1)   return -1;
        int right_depth = depth(node.right);
        if (right_depth == -1)   return -1;
        if (Math.abs(left_depth - right_depth) > 1)
            return -1;
        return Math.max(left_depth, right_depth) + 1;
    }
}