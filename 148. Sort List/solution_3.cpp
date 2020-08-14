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
    ListNode *merge(ListNode *l, ListNode *r) {
        if (!l) return r;
        if (!r) return l;
        ListNode *pre = new ListNode(-1), *ptr = pre;
        while (l && r) {
            if (l->val < r->val) {
                ptr->next = l;
                l = l->next;
            }
            else {
                ptr->next = r;
                r = r->next;
            }
            ptr = ptr->next;
        }
        if (l)  ptr->next = l;
        if (r)  ptr->next = r;
        return pre->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head)  return nullptr;
        if (!head->next)    return head;
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr;
        head = sortList(head);
        mid = sortList(mid);
        head = merge(head, mid);
        return head;
    }
};