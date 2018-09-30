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
    public boolean isSubtree(TreeNode s, TreeNode t) {
        return isSubtreeRecur(s, t, 0);
    }
    private boolean isSubtreeRecur(TreeNode s, TreeNode t, int depth) {
        if (s == null && t == null)
            return true;
        if (s == null || t == null)
            return false;
        if (s.val == t.val) {
            if (isSubtreeRecur(s.left, t.left, depth + 1) && isSubtreeRecur(s.right, t.right, depth + 1))
                return true;
        }
        else if (depth > 0)
            return false;
        return isSubtreeRecur(s.left, t, depth) || isSubtreeRecur(s.right, t, depth);
    }
}