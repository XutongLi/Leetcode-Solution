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
    TreeNode *helper(ListNode *head, ListNode *tail) {
        if (head == tail)
            return nullptr;
        ListNode *fast = head, *slow = head;
        while (fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = helper(head, slow);
        root->right = helper(slow->next, tail);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, nullptr);
    }
};
//根节点为链表段的中点
//O(nlogn)