//O(nlogn)
//以每个结点作为根结点进行遍历
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
    private int count = 0;
    public int pathSum(TreeNode root, int sum) {
        if (root == null)   return 0;
        countNode(root, sum);
        pathSum(root.left, sum);
        pathSum(root.right, sum);
        return count;
    }
    private void countNode(TreeNode root, int sum) {
        if (root == null)   return;
        if (root.val == sum)    count++;
        countNode(root.left, sum - root.val);
        countNode(root.right, sum - root.val);
    }
}