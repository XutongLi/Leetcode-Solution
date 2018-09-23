//100%
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 * [1,2,3,4,5,6,null,8,null,9,null,null,null,10,null,null,11,10,null,null,11]
 */
class Solution {
    private int max = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null)   return 0;
        findMax(root);
        return max;
    }
    private int findMax(TreeNode node) {
        if (node == null)  return 0;
        int dl = findMax(node.left);
        int dr = findMax(node.right);
        max = Math.max(dl + dr, max);
        return Math.max(dl, dr) + 1;
    }
}