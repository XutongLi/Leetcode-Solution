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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        return str(root1).equals(str(root2));
    }
    private String str(TreeNode root) {
        if (root == null)   return "";
        if (root.left == null && root.right == null)
            return root.val + "-";
        return str(root.left) + str(root.right);
    }
}