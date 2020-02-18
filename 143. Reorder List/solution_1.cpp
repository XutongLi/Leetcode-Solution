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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        
        //find mid
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *right = slow->next;   //right is the head list of the right list
        slow->next = nullptr;
        
        //reverse right
        fast = right;
        slow = nullptr;
        while (fast) {
            ListNode *tmp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = tmp;
        }   //slow is the head pointer of reversed list
        
        //merge two list
        ListNode *ptr = head;
        while (slow) {
            ListNode *tmp = ptr->next;
            ptr->next = slow;
            slow = slow->next;
            ptr->next->next = tmp;
            ptr = tmp;
        }
    }
};