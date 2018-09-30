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
    private int idx = 0;
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        ArrayList<Integer> list = new ArrayList<>();
        getList(root1, list);
        return isSim(root2, list);
    }
    private void getList(TreeNode root, ArrayList<Integer> list) {
        if (root.left == null && root.right == null)
            list.add(root.val);
        if (root.left != null)
            getList(root.left, list);
        if (root.right != null)
            getList(root.right, list);
    }
    private boolean isSim(TreeNode root, ArrayList<Integer> list) {
        if (root.left == null &&root.right == null) {
            if (root.val != list.get(idx++))
                return false;
        }
        else if (root.left != null && root.right == null)
            return isSim(root.left, list);
        else if (root.right != null && root.left == null)
            return isSim(root.right, list);
        else
            return isSim(root.left, list) && isSim(root.right, list);
        return true;
            
    }
}