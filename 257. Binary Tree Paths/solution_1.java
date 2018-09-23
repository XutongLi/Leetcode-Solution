//93%
//DFS
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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> list = new LinkedList<>();
        if (root == null)   return list;
        findPath(root, "", list);
        return list;
    }
    private void findPath(TreeNode node, String str, List<String> list) {   
        str += "->" + String.valueOf(node.val);
        if (node.left == null && node.right == null) 
            list.add(str.substring(2));
        if (node.left != null)
            findPath(node.left, str, list);
        if (node.right != null)
            findPath(node.right, str, list);
    }
}