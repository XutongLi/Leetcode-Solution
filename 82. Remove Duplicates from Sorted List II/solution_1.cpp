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
        ListNode *help = new ListNode(-1);
        help->next = head;
        ListNode *tmp = help;
        while (tmp && tmp->next) {
            int repeat = false;
            while (tmp->next->next && tmp->next->val == tmp->next->next->val) {
                tmp->next= tmp->next->next;
                repeat = true;
            }
            if (repeat)
                tmp->next = tmp->next->next;
            else
                tmp = tmp->next;
        }
        return help->next;
    }
};