/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head)  return nullptr;
        ListNode *fast = head, *slow = nullptr;
        int n = k;
        while (n -- && fast) {
            ListNode *tmp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = tmp;
        }
        if (n < 0) {
            head->next = reverseKGroup(fast, k);
            return slow;
        } 
        else {
            while (fast != head) {
                ListNode *tmp = slow->next;
                slow->next = fast;
                fast = slow;
                slow = tmp;
            }
            return fast;
        }
    }
};