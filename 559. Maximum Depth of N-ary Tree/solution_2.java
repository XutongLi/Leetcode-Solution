/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    private int max = 0;
    public int maxDepth(Node root) {
        if (root == null)   return 0;
        dfs(root, 0);
        return max;
    }
    private void dfs(Node node, int dep) {
        if (node == null)   return;
        dep++;
        if (node.children.isEmpty()) {
            max = Math.max(dep, max);
            return;
        }
        else {
            for (Node x : node.children)
                dfs(x, dep);
        }    
        
    }
}