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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        ListNode fake(INT_MIN);
        fake.next = head;
        ListNode* p = & fake;
        while (p->next != NULL) {
            if (p->next->val == val) {
                p->next = p->next->next;
            }
            else
                p = p->next;
        }
        return fake.next;
    }
};