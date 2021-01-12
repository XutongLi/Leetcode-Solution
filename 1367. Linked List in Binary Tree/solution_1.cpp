/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool findPath(ListNode *ptr, TreeNode *root) {
        if (!ptr)	return true;
        if (!root)	return false;
        if (ptr->val == root->val) {
            if (findPath(ptr->next, root->left) || findPath(ptr->next, root->right))
                return true;
        }
        return false;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root)  return false;
        return findPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
