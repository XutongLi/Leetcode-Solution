//99.78%
//recursion
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
        levelAdd(root, 0, res);
        return res;
    }
    private void levelAdd(TreeNode node, int depth, LinkedList<List<Integer>> res) {
        if (node == null)   return;
        if (res.size() < depth + 1) 
            res.addFirst(new ArrayList<Integer>());
        levelAdd(node.left, depth + 1, res);
        levelAdd(node.right, depth + 1, res);
        res.get(res.size() - depth - 1).add(node.val);
    }
}