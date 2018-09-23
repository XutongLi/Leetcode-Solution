//100%
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
    public int minDepth(TreeNode root) {
        if (root == null)   return 0;
        Queue<TreeNode> queue = new LinkedList<>();
        int depth = 1;
        queue.offer(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode tmp = queue.poll();
                //判断每一层是否为叶节点
                if (tmp.left == null && tmp.right == null)
                    return depth;
                if (tmp.left != null) 
                    queue.offer(tmp.left);
                if (tmp.right != null) 
                    queue.offer(tmp.right); 
            }
            depth++;
        }
        return depth;
    }
}