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
    private int sum = 0;
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null)   return 0;
        getSum(root, false);
        return sum;
    }
    private void getSum(TreeNode node, boolean isLeft) {
        if (node.left == null && node.right == null && isLeft) {
            sum += node.val;
            return;
        }
        if (node.left != null) 
            getSum(node.left, true);
        if (node.right != null)
            getSum(node.right, false);
    }
}