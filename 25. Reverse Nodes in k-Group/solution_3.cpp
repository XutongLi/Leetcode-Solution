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
private:
    ListNode *reverse(ListNode *start, ListNode *end) {
        ListNode *fast = start->next, *slow = end;
        while (fast != end) {
            ListNode *tmp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = tmp;
        }
        return slow;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = k;
        ListNode *pre = new ListNode (-1);
        pre->next = head;
        ListNode *p = head, *start = pre;
        while (p) {
            while (-- cnt > 0 && p->next) {
                p = p->next;
            }
            if (cnt > 0) 
                break;
            ListNode *next = p->next, *start_next = start->next;
            start->next = reverse(start, next);
            start = start_next;
            p = next;
            cnt = k;
        }
        return pre->next;
    }
};