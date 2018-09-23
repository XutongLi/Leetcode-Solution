//20%
//BFS
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
    public boolean isSymmetric(TreeNode root) {
        if (root == null)   return true;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()) {
            int size = q.size();
            ArrayList<TreeNode> list = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                TreeNode tmp = q.poll();
                list.add(tmp);
                if (tmp != null) {
                    if (tmp.left == null) q.offer(null);
                    else    q.offer(tmp.left);
                    if (tmp.right == null) q.offer(null);
                    else    q.offer(tmp.right);
                }
            }
            for (int i = 0; i < list.size() / 2; i++) {
                TreeNode le = list.get(i);
                TreeNode ri = list.get(list.size() - i - 1);
                if (le != null && ri != null && le.val != ri.val)
                    return false;
                if (le != null && ri == null || le == null && ri != null)
                    return false;
            }
        }
        return true;
    }
}