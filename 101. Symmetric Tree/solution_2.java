//100%
//DFS
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
    public boolean isSymmetric(TreeNode root) {
        if (root == null)   return true;
        return isSymmetric(root.left, root.right);
    }
    private boolean isSymmetric(TreeNode le, TreeNode ri) {
        if (le == null && ri == null)
            return true;
        if (le != null && ri != null && le.val == ri.val)
            return isSymmetric(le.left, ri.right) && isSymmetric(le.right, ri.left);
        return false;
        
    }
}