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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return nullptr;
        int len = 1;
        ListNode *tail = head;
        while (tail->next) {
            ++ len;
            tail = tail->next;
        }
        k = k % len;
        if (k == 0)
            return head;
        ListNode *fake = new ListNode(-1);
        fake->next = head;
        ListNode *ptr = fake;
        for (int i = 0; i < len - k; ++ i) 
            ptr = ptr->next;
        fake->next = ptr->next;
        tail->next = head;
        ptr->next = nullptr;
        return fake->next;
    }
};