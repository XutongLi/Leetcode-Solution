//99.78%
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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        LinkedList<List<Integer>> res = new LinkedList<>();
        if (root == null)   return res;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> in = new LinkedList<>();
            for (int i = 0; i < size; i++) {
                TreeNode tmp = queue.poll();
                in.add(tmp.val);
                if (tmp.left != null)   queue.offer(tmp.left);
                if (tmp.right != null)  queue.offer(tmp.right);
            }
            res.addFirst(in);
        }
        return res;
    }
}