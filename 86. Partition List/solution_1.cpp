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
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return nullptr;
        ListNode small_head(0);
        ListNode big_head(0);
        ListNode *ptr = head, *small = &small_head, *big = &big_head;
        while (ptr) {
            if (ptr->val < x) {
                small->next = ptr;
                small = small->next;
            }
            else {
                big->next = ptr;
                big = big->next;
            }
            ptr = ptr->next;
        }
        small->next = big_head.next;
        big->next = nullptr;
        return small_head.next;
    }
};
//two pointer