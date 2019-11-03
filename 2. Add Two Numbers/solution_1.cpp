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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pres = new ListNode(-1);
        ListNode *head = pres;
        int flag = 0;
        while (l1 != NULL || l2 != NULL) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + flag;
            if (sum >= 10) {
                sum -= 10;
                flag = 1;
            }
            else
                flag = 0;
            pres->next = new ListNode(sum);
            pres = pres->next;
            l1 = l1 == NULL ? l1 : l1->next;
            l2 = l2 == NULL ? l2 : l2->next;
        }
        if (flag == 1)
            pres->next = new ListNode(1);
        return head->next;
    }
};