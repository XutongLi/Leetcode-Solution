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
    public int minDepth(TreeNode root) {
        if (root == null)  return 0;
        return findMin(root);
    }
    private int findMin(TreeNode node) {
        if (node.left != null && node.right != null) {
            return Math.min(findMin(node.left), findMin(node.right)) + 1;
        }
        else if (node.left != null)
            return findMin(node.left) + 1;
        else if (node.right != null)
            return findMin(node.right) + 1;
        else 
            return 1;
    }
}