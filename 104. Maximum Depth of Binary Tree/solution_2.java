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
    private int max = 0;
    public int maxDepth(TreeNode root) {
        if (root == null)   return 0;
        depth(root, 0);
        return max;
        
    }
    private void depth(TreeNode node, int dep) {
        dep++;
        if (node.left == null && node.right == null) {
            max = Math.max(dep, max);
            return;
        }
        if (node.left != null)
            depth(node.left, dep);
        if (node.right != null) 
            depth(node.right, dep);
        
    }
}