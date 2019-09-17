/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)  return NULL;
        ListNode* p = head;
        while (p != NULL && p->next != NULL) {
            if (p->val == p->next->val) {
                p->next = p->next->next;
            }
            else
                p = p->next;
        }
        return head;
    }
};