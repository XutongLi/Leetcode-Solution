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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        int len = getLen(head);
        ListNode *pre = new ListNode(-1);
        pre->next = head;
        ListNode *left, *right, *cur, *tail;
        for (int step = 1; step < len; step <<= 1) {
            tail = pre;
            cur = pre->next;
            while (cur) {
                left = cur;
                right = split(left, step);
                cur = split(right, step);
                tail = merge(left, right, tail);
            }
        }
        return pre->next;
    }
    int getLen(ListNode *head) {
        ListNode *ptr = head;
        int len = 0;
        while (ptr) {
            ++ len;
            ptr = ptr->next;
        }
        return len;
    }
    ListNode *split(ListNode *node, int n) {
        for (int i = 1; i < n && node; ++ i) 
            node = node->next;
        if (!node)
            return nullptr;
        ListNode *next = node->next;
        node->next = nullptr;
        return next;
    }
    ListNode *merge(ListNode *l, ListNode *r, ListNode *head) {
        ListNode *ptr = head;
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
        ptr->next = l ? l : r;
        while (ptr->next)
            ptr = ptr->next;
        return ptr;
    }
};
//bottom to up merge
//time O(nlogn)
//space O(1)