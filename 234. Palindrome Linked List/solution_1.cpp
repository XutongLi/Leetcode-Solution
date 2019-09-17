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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode* mid = middleNode(head);
        ListNode* last = reverseList(mid);
        while (last != NULL) {
            if (head->val != last->val)
                return false;
            head = head->next;
            last = last->next;
        }
        return true;
    }
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return fast  == NULL ? slow : slow->next;
    }
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* fast = head;
        ListNode* slow = NULL;
        while (fast != NULL) {
            ListNode* tmp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = tmp;
        }
        return slow;
    }
};