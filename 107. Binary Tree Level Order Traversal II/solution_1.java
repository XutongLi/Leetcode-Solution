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
        Queue<TreeNode> queue = new LinkedList<>();
        //Stack<List<Integer>> stack = new Stack<>();
        LinkedList<List<Integer>> res = new LinkedList<>();
        List<Integer> in = new LinkedList<>();
        if (root == null) {
            return res;
        }
        int count = 1;
        int nextcount = 0;
        queue.offer(root);
        while (!queue.isEmpty()) {
            TreeNode tmp = queue.poll();
            if (count-- > 0)    
                in.add(tmp.val);
            if (tmp.left != null) {
                nextcount++; 
                queue.offer(tmp.left);
            }
            if (tmp.right != null) {
                nextcount++;
                queue.offer(tmp.right);
            }
            if (count == 0) {
                res.addFirst(in);
                in = new LinkedList<>();
                //in.clear();
                count = nextcount;
                nextcount = 0;
            }
        }
        return res;
    }
}