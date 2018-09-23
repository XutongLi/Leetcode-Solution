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
        return calcu(root, 0, sum);
    }
    private boolean calcu(TreeNode node, int temp, int sum) {
        int num = temp + node.val;
        if (node.left == null && node.right == null)
            if (num == sum)
                return true;
            else
                return false;
        else if (node.right == null)
            return calcu(node.left, num, sum);
        else if (node.left == null)
            return calcu(node.right, num, sum);
        else 
            return calcu(node.left, num, sum) || calcu(node.right, num, sum);
        
    }
}