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
    private int tmp = 0;
    public TreeNode convertBST(TreeNode root) {
        if (root == null)   return null;
        helper(root);
        return root;
        
    }
    private void helper(TreeNode node) {
        if (node == null)   return;
        helper(node.right);
        node.val += tmp;
        tmp = node.val;
        helper(node.left);
    }
}