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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *fake = new ListNode(-1);
        fake->next = head;
        int i = 1;
        ListNode *fast = head->next, *slow = head, *pre = fake;
        while (i < m) {
            fast = fast->next;
            slow = slow->next;
            pre = pre->next;
            ++ i;
        }
        ListNode *start = slow;
        while (i < n) {
            ListNode *tmp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = tmp;
            ++ i;
        }
        pre->next = slow;
        start->next = fast;
        return fake->next;
    }
};