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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode fake_head(0);
        fake_head.next = head;
        ListNode *ptr = &fake_head;
        while (ptr->next && ptr->next->next) {
            ListNode *tmp = ptr->next->next->next;
            ptr->next->next->next = ptr->next;
            ptr->next = ptr->next->next;
            ptr->next->next->next = tmp;
            ptr = ptr->next->next;
        }
        return fake_head.next;
    }
};