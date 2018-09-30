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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        ArrayList<Integer> list1 = new ArrayList<>();
        ArrayList<Integer> list2 = new ArrayList<>();
        getList(root1, list1);
        getList(root2, list2);
        if (list1.size() != list2.size())
            return false;
        else {
            for (int i = 0; i < list1.size(); i++) 
                if (list1.get(i) != list2.get(i))
                    return false;
        }
        return true;
    }
    private void getList(TreeNode root, ArrayList<Integer> list) {
        if (root == null)   return;
        if (root.left == null && root.right == null)
            list.add(root.val);
        getList(root.left, list);
        getList(root.right, list);
    }
}